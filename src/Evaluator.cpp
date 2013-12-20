//
//  Evaluator.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 20/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <iostream>

#include "Evaluator.h"

#include "InstructionBlock.h"
#include "Function.h"
#include "Program.h"
#include "AssignmentInstruction.h"
#include "Constant.h"
#include "Variable.h"
#include "FunctionCallInstruction.h"
#include "ArithmeticOperationInstruction.h"
#include "ReadInstruction.h"
#include "PrintInstruction.h"
#include "ConditionalInstruction.h"
#include "IfBlock.h"
#include "WhileBlock.h"
#include "ReturnInstruction.h"

using std::cin;
using std::cout;
using std::endl;



Evaluator::Evaluator(Program const& program): m_program(program)
{
}

void Evaluator::execute_program()
{
    visit(m_program);
}

int Evaluator::visit(Constant const& instruction)
{
    return instruction.value();
}

int Evaluator::visit(Variable const& instruction)
{
    variable_scope::iterator variable = scope().find(instruction.name());
    if (variable == scope().end())
        return 0;
    return variable->second;
}

int Evaluator::visit(Program const& instruction)
{
    variable_scope program_scope;
    in_function(program_scope);
    for (instructions::const_iterator it = instruction.functions().begin(); it != instruction.functions().end(); ++it)
        (*it)->accept_visit(this);
    instruction.InstructionBlock::accept_visit(this);
    out_function();
    return m_result;
}

int Evaluator::visit(Function const& instruction)
{
    m_function_scope[instruction.name()] = &instruction;
    return 0;
}

int Evaluator::visit(AssignmentInstruction const& instruction)
{
    int value = instruction.expression()->accept_visit(this);
    scope()[instruction.name()] = value;
    return m_result;
}

int Evaluator::visit(FunctionCallInstruction const& instruction)
{
    function_scope::const_iterator func = m_function_scope.find(instruction.name());
    if (func == m_function_scope.end())
        return 0;
    
    Function const* function_to_call = func->second;
    
    if (function_to_call->arguments().size() != instruction.arguments().size())
        return 0;
    
    variable_scope function_to_call_scope;
    
    for (size_t i = 0; i != instruction.arguments().size(); ++i)
        function_to_call_scope[function_to_call->arguments()[i]] = instruction.arguments()[i]->accept_visit(this);
    
    in_function(function_to_call_scope);
    
    function_to_call->InstructionBlock::accept_visit(this);
    
    out_function();
    return on_return();
}

int Evaluator::visit(ArithmeticOperationInstruction const& instruction)
{
    int left = instruction.left_operand()->accept_visit(this);
    int right = instruction.right_operand()->accept_visit(this);
    
    switch (instruction.operation())
    {
        case kAdd:
            return left + right;
            
        case kSub:
            return left - right;
            
        case kMul:
            return left * right;
            
        case kDiv:
            {
                if (right == 0)
                    return 0;
                
                return left / right;
            }
            
        default:
            return 0;
    }
}

int Evaluator::visit(ReadInstruction const& instruction)
{
    cin >> scope()[instruction.variable()];
    return m_result;
}

int Evaluator::visit(PrintInstruction const& instruction)
{
    int result = instruction.expression()->accept_visit(this);
    cout << result << endl;
    return m_result;
}

int Evaluator::visit(ConditionalInstruction const& instruction)
{
    int left = instruction.left_operand()->accept_visit(this);
    int right = instruction.right_operand()->accept_visit(this);
    
    switch (instruction.operation())
    {
        case kEqual:
            return left == right;
            
        case kNotEqual:
            return left != right;
            
        case kLess:
            return left < right;
            
        case kGreater:
            return left > right;
            
        case kLessEqual:
            return left <= right;
            
        case kGreaterEqual:
            return left >= right;
            
        default:
            return 0;
    }
}

int Evaluator::visit(IfBlock const& instruction)
{
    if (instruction.condition()->accept_visit(this))
        instruction.InstructionBlock::accept_visit(this);
    return m_result;
}

int Evaluator::visit(WhileBlock const& instruction)
{
    while (instruction.condition()->accept_visit(this))
        instruction.InstructionBlock::accept_visit(this);
    return m_result;
}

int Evaluator::visit(ReturnInstruction const& instruction)
{
    int result = instruction.expression()->accept_visit(this);
    set_return_value(result);
    return m_result;
}

int Evaluator::visit(InstructionBlock const& instruction)
{
    for (instructions::const_iterator it = instruction.block().begin(); it != instruction.block().end() && !has_returned(); ++it)
    {
        (*it)->accept_visit(this);
    }
    return m_result;
}

void Evaluator::set_return_value(int value)
{
    m_has_returned = true;
    m_result = value;
}

int Evaluator::on_return()
{
    int result = m_result;
    m_result = 0;
    m_has_returned = false;
    return result;
}

void Evaluator::in_function(variable_scope& scope)
{
    m_variable_scopes.push(scope);
}

void Evaluator::out_function()
{
    m_variable_scopes.pop();
}

variable_scope& Evaluator::scope()
{
    return m_variable_scopes.top();
}