//
//  LexemeTypes.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "LexemeTypes.h"
#include "Lexeme.h"

Lexeme handle_separator(char separator, int line, int column)
{
    switch (separator)
    {
        case ',':
            return Lexeme(kComma, "", line, column);
        case ':':
            return Lexeme(kColon, "", line, column);
        case '(':
            return Lexeme(kLeftBracket, "", line, column);
        case ')':
            return Lexeme(kRightBracket, "", line, column);
        default:
            return Lexeme(kUnknownLexeme, "", line, column);
    }
}

Lexeme handle_number(string number, int line, int column)
{
    return Lexeme(kNumber, number, line, column);
}

Lexeme handle_alphanumeric(string alphanumeric, int line, int column)
{
    LexemeTypes type = kId;
    if (alphanumeric == "if")
        type = kIfKeyword;
    if (alphanumeric == "end")
        type = kEndKeyword;
    if (alphanumeric == "def")
        type = kDefKeyword;
    if (alphanumeric == "read")
        type = kReadKeyword;
    if (alphanumeric == "print")
        type = kPrintKeyword;
    if (alphanumeric == "while")
        type = kWhileKeyword;
    if (alphanumeric == "return")
        type = kReturnKeyword;
    
    return Lexeme(type, alphanumeric, line, column);
}

Lexeme handle_operation(string operation, int line, int column)
{
    return Lexeme(determine_operation_type(operation), "", line, column);
}

LexemeTypes determine_operation_type(string operation)
{
    LexemeTypes type = kUnknownLexeme;
    if (operation.length() == 1)
    {
        switch (operation[0])
        {
            case '=':
                type = kAssignment;
                break;
            case '<':
                type = kLessOperation;
                break;
            case '>':
                type = kGreaterOperation;
                break;
            case '-':
                type = kSubtraction;
                break;
            case '+':
                type = kAddition;
                break;
            case '/':
                type = kDivision;
                break;
            case '*':
                type = kMultiplication;
                break;
            default:
                type = kUnknownLexeme;
                break;
        }
    }
    else
    {
        if (operation == "==")
            type = kEqualOperation;
        if (operation == "!=")
            type = kNotEqualOperation;
        if (operation == "<=")
            type = kLessEqualOperation;
        if (operation == ">=")
            type = kGreaterEqualOperation;
    }
    return type;
}

Lexeme end_of_line(int line, int column)
{
    return Lexeme(kEndofLine, "", line, column);
}