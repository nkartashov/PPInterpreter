//
//  Parser.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <cstdlib>

#include "LexemeTypes.h"
#include "Parser.h"
#include "ErrorHandler.h"

#include "Lexeme.h"

#include "Declarations.h"
#include "Program.h"
#include "Function.h"
#include "AssignmentInstruction.h"
#include "Constant.h"
#include "Variable.h"
#include "FunctionCallInstruction.h"
#include "ArithmeticOperationInstruction.h"
#include "ConditionalInstruction.h"
#include "ReadInstruction.h"
#include "PrintInstruction.h"
#include "IfBlock.h"
#include "WhileBlock.h"
#include "ReturnInstruction.h"


Parser::Parser(vector<Lexeme>& lexemes):
m_lexemes(lexemes),
m_current_lexeme_index(0),
m_buf_lexeme_index(0)
{
    m_program = parse_program();
}

void Parser::report_current_syntax_error()
{
    ErrorHandler::report_syntax_error(current_lexeme().line());
}

bool Parser::match_lexeme_simple_arithmetic(Lexeme lexeme)
{
    return lexeme.type() == kAddition || current_lexeme().type() == kSubtraction;
}

bool Parser::match_lexeme_complex_arithmetic(Lexeme lexeme)
{
    return lexeme.type() == kMultiplication || current_lexeme().type() == kDivision;
}

bool Parser::match_lexeme_logic(Lexeme lexeme)
{
    LexemeTypes t = lexeme.type();
    
    return t == kEqualOperation ||
    t == kNotEqualOperation ||
    t == kLessOperation ||
    t == kGreaterOperation ||
    t == kLessEqualOperation ||
    t == kGreaterEqualOperation;
}

bool Parser::match_current_lexeme_simple_arithmetic()
{
    return match_lexeme_simple_arithmetic(current_lexeme());
}

bool Parser::match_current_lexeme_complex_arithmetic()
{
    return match_lexeme_complex_arithmetic(current_lexeme());
}

bool Parser::match_current_lexeme_logic()
{
    return match_lexeme_logic(current_lexeme());
}

Lexeme const& Parser::current_lexeme()
{
    return m_lexemes[m_current_lexeme_index];
}

bool Parser::match_current_lexeme(LexemeTypes type)
{
    return match_lexeme(type, current_lexeme());
}

bool Parser::match_lexeme(LexemeTypes type, Lexeme lexeme)
{
    return lexeme.type() == type;
}

void Parser::next_line()
{
    if (match_current_lexeme(kEndofLine))
        next_lexeme();
    else
        report_current_syntax_error();
}

bool Parser::finished()
{
    return !(m_current_lexeme_index + 1 < m_lexemes.size());
}

void Parser::save()
{
    m_buf_lexeme_index = m_current_lexeme_index;
}

void Parser::restore()
{
    m_current_lexeme_index = m_buf_lexeme_index;
}

Lexeme const& Parser::next_lexeme()
{
    if (!finished())
        return m_lexemes[++m_current_lexeme_index];

    return current_lexeme();
}

int Parser::parse_number(string str)
{
    return atoi(str.c_str());
}

program_ptr Parser::parse_program()
{
    int start_line = current_lexeme().line();
    instructions program_body;
    instructions functions;
    instruction_ptr instruction = 0;
    
    while (match_current_lexeme(kEndofLine))
        next_line();
    
    while (!finished())
    {
        instruction = 0;
        
        instruction = parse_function_definition();
        
        if (instruction)
        {
            functions.push_back(instruction);
            continue;
        }

        instruction = parse_instruction();
        
        if (!instruction)
        {
            report_current_syntax_error();
            return 0;
        }
        
        program_body.push_back(instruction);
    }
    
    return program_ptr(new Program(start_line, program_body, functions));
}

instruction_ptr Parser::parse_instruction()
{
    if (!ErrorHandler::is_ok())
        return 0;
    
    save();
    instruction_ptr result = parse_assignment();
    
    if (!result)
    {
        restore();
        result = parse_function_call();
    }
    
    if (!result)
        result = parse_if_block();
    
    if (!result)
        result = parse_while_block();
    
    if (!result)
        result = parse_return();
    
    if (!result)
        result = parse_print();
    
    if (!result)
        result = parse_read();
    
    if (result)
        next_line();
    
    return result;
}

instruction_ptr Parser::parse_print()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kPrintKeyword))
        return 0;
    
    next_lexeme();
    
    instruction_ptr expression = parse_expression();
    
    if (!expression)
    {
        report_current_syntax_error();
        return 0;
    }
    
    return instruction_ptr(new PrintInstruction(start_line, expression));
}

instruction_ptr Parser::parse_read()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kReadKeyword))
        return 0;
    
    next_lexeme();
    
    if (!match_current_lexeme(kId))
    {
        report_current_syntax_error();
        return 0;
    }
    
    string name = current_lexeme().value();
    
    next_lexeme();
    
    return instruction_ptr(new ReadInstruction(start_line, name));
}

instruction_ptr Parser::parse_assignment()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kId))
        return 0;
    
    string name = current_lexeme().value();
    
    next_lexeme();
    
    if (!match_current_lexeme(kAssignment))
        return 0;
    
    next_lexeme();
    
    instruction_ptr expression = parse_expression();
    
    if (!expression)
    {
        report_current_syntax_error();
        return 0;
    }
    
    return instruction_ptr(new AssignmentInstruction(start_line, name, expression));
}

instruction_ptr Parser::parse_return()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kReturnKeyword))
        return 0;
    
    next_lexeme();
    
    instruction_ptr expression = parse_expression();
    
    if (!expression)
    {
        report_current_syntax_error();
        return 0;
    }
    
    return instruction_ptr(new ReturnInstruction(start_line, expression));
}

instruction_ptr Parser::parse_if_block()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kIfKeyword))
        return 0;
    
    next_lexeme();
    
    instruction_ptr condition = parse_condition();
    
    if(!condition)
    {
        report_current_syntax_error();
        return 0;
    }

    if(!match_current_lexeme(kColon))
    {
        report_current_syntax_error();
        return 0;
    }
    
    next_lexeme();
    
    next_line();
    
    instructions block;
    
    while (!match_current_lexeme(kEndKeyword))
    {
        instruction_ptr instruction = parse_instruction();
        
        if (!instruction)
        {
            report_current_syntax_error();
            return 0;
        }
        
        block.push_back(instruction);
    }
    
    next_lexeme();
    return instruction_ptr(new IfBlock(start_line, block, condition));
}

instruction_ptr Parser::parse_while_block()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kWhileKeyword))
        return 0;
    
    next_lexeme();
    
    instruction_ptr condition = parse_condition();
    
    if(!condition)
    {
        report_current_syntax_error();
        return 0;
    }
    
    if(!match_current_lexeme(kColon))
    {
        report_current_syntax_error();
        return 0;
    }
    
    next_lexeme();
    
    next_line();
    
    instructions block;
    
    while (!match_current_lexeme(kEndKeyword))
    {
        instruction_ptr instruction = parse_instruction();
        
        if (!instruction)
        {
            report_current_syntax_error();
            return 0;
        }
        
        block.push_back(instruction);
    }
    
    next_lexeme();
    return instruction_ptr(new WhileBlock(start_line, block, condition));
}

instruction_ptr Parser::parse_function_definition()
{
    int start_line = current_lexeme().line();
    if (!match_current_lexeme(kDefKeyword))
        return 0;
    
    next_lexeme();
    
    if (!match_current_lexeme(kId))
    {
        report_current_syntax_error();
        return 0;
    }
    
    string name = current_lexeme().value();
    
    next_lexeme();
    
    if (!match_current_lexeme(kLeftBracket))
    {
        report_current_syntax_error();
        return 0;
    }
    
    next_lexeme();
    
    vector<string> parameters;
    
    if (!match_current_lexeme(kRightBracket))
    {
        while (true)
        {
            if (!match_current_lexeme(kId))
            {
                report_current_syntax_error();
                return 0;
            }
            
            parameters.push_back(current_lexeme().value());
            
            next_lexeme();
            
            if (!match_current_lexeme(kComma))
                break;
            
            next_lexeme();
        }
    }
    
    if (!match_current_lexeme(kRightBracket))
    {
        report_current_syntax_error();
        return 0;
    }
    
    next_lexeme();
    
    if (!match_current_lexeme(kColon))
    {
        report_current_syntax_error();
        return 0;
    }
    
    next_lexeme();
    
    next_line();
    
    instructions function_body;
    
    while (!match_current_lexeme(kEndKeyword))
    {
        instruction_ptr instruction = parse_instruction();
        if (!instruction)
        {
            report_current_syntax_error();
            return 0;
        }
        
        function_body.push_back(instruction);
    }
    
    next_lexeme();
    
    next_line();
    
    return instruction_ptr(new Function(start_line, function_body, name, parameters));
}

instruction_ptr Parser::parse_constant()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kNumber))
        return 0;
    
    string value = current_lexeme().value();
    
    next_lexeme();
    
    return instruction_ptr(new Constant(start_line, parse_number(value)));
}

instruction_ptr Parser::parse_expression()
{
    int start_line = current_lexeme().line();
    
    instruction_ptr left = parse_term();
    
    if (!left)
        return 0;
    
    if (!match_current_lexeme_simple_arithmetic())
        return left;
    
    Lexeme lexeme = current_lexeme();
    
    next_lexeme();
    
    instruction_ptr right = parse_expression();
    
    if (!right)
    {
        report_current_syntax_error();
        return 0;
    }
    
    switch (lexeme.type())
    {
        case kAddition:
            return instruction_ptr(new ArithmeticOperationInstruction(start_line, kAdd, left, right));
        case kSubtraction:
            return instruction_ptr(new ArithmeticOperationInstruction(start_line, kSub, left, right));
        default:
        {
            report_current_syntax_error();
            return 0;
        }
    }
}

instruction_ptr Parser::parse_function_call()
{
    int start_line = current_lexeme().line();
    
    if (!match_current_lexeme(kId))
        return 0;
    
    string name = current_lexeme().value();
    
    next_lexeme();
    
    if (!match_current_lexeme(kLeftBracket))
        return instruction_ptr(new Variable(start_line, name));
    
    next_lexeme();
    
    instructions parameters;
    if (!match_current_lexeme(kRightBracket))
    {
        while (true)
        {
            instruction_ptr parameter = parse_expression();
            if (!parameter)
            {
                report_current_syntax_error();
                {
                    report_current_syntax_error();
                    return 0;
                }
            }
            
            parameters.push_back(parameter);
            if (!match_current_lexeme(kComma))
                break;
            else
                next_lexeme();
        }
        
        if (!match_current_lexeme(kRightBracket))
        {
            report_current_syntax_error();
            {
                report_current_syntax_error();
                return 0;
            }
        }
    }
    
    next_lexeme();

    return instruction_ptr(new FunctionCallInstruction(start_line, name, parameters));
}

instruction_ptr Parser::parse_term()
{
    int start_line = current_lexeme().line();
    
    instruction_ptr left = parse_value();
    
    if (!left)
        return 0;
    
    if (!match_current_lexeme_complex_arithmetic())
        return left;
    
    Lexeme lexeme = current_lexeme();
    
    next_lexeme();
    
    instruction_ptr right = parse_term();
    
    if (!right)
    {
        report_current_syntax_error();
        return 0;
    }
    
    switch (lexeme.type())
    {
        case kMultiplication:
            return instruction_ptr(new ArithmeticOperationInstruction(start_line, kMul, left, right));
        case kDivision:
            return instruction_ptr(new ArithmeticOperationInstruction(start_line, kDiv, left, right));
        default:
        {
            report_current_syntax_error();
            return 0;
        }
    }
}

instruction_ptr Parser::parse_value()
{
    int start_line = current_lexeme().line();
    
    if (match_current_lexeme(kSubtraction))
    {
        next_lexeme();
        
        instruction_ptr value = parse_value();
        if (!value)
        {
            report_current_syntax_error();
            return 0;
        }
        
        return instruction_ptr(new ArithmeticOperationInstruction(start_line, kSub, instruction_ptr(new Constant(start_line, 0)), value));
    }
    
    if (match_current_lexeme(kLeftBracket))
    {
        next_lexeme();
        instruction_ptr expression = parse_expression();
        
        if (!match_current_lexeme(kRightBracket))
        {
            report_current_syntax_error();
            return 0;
        }
        
        next_lexeme();
        
        return expression;
    }
    
    instruction_ptr value = parse_constant();
    if (!value)
        value = parse_function_call();
    
    return value;
}

instruction_ptr Parser::parse_condition()
{
    int start_line = current_lexeme().line();
    
    instruction_ptr left = parse_expression();
    
    if (!left)
    {
        report_current_syntax_error();
        return 0;
    }
    
    if (!match_lexeme_logic(current_lexeme()))
    {
        report_current_syntax_error();
        return 0;
    }
    
    Lexeme lexeme = current_lexeme();
    
    next_lexeme();
    
    instruction_ptr right = parse_expression();
    
    if (!right)
    {
        report_current_syntax_error();
        return 0;
    }
    
    switch (lexeme.type())
    {
        case kEqualOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kEqual, left, right));
        case kNotEqualOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kNotEqual, left, right));
        case kLessOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kLess, left, right));
        case kGreaterOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kGreater, left, right));
        case kLessEqualOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kLessEqual, left, right));
        case kGreaterEqualOperation:
            return instruction_ptr(new ConditionalInstruction(start_line, kGreaterEqual, left, right));
        default:
        {
            report_current_syntax_error();
            return 0;
        }
    }
}