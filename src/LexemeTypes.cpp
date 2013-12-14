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
    
    return Lexeme(type, alphanumeric, line, column);
}

Lexeme handle_operation(string operation, int line, int column)
{
    if (operation.length() == 1)
    {
        switch (operation[0])
        {
            case '=':
                return Lexeme(kAssignment, "", line, column);
            case '<':
                return Lexeme(kLessOperation, "", line, column);
            case '>':
                return Lexeme(kGreaterOperation, "", line, column);
            case '-':
                return Lexeme(kSubtraction, "", line, column);
            case '+':
                return Lexeme(kAddition, "", line, column);
            case '/':
                return Lexeme(kDivision, "", line, column);
            case '*':
                return Lexeme(kMultiplication, "", line, column);
            default:
                return Lexeme(kUnknownLexeme, "", line, column);
        }
    }
    else
    {
        LexemeTypes type = kUnknownLexeme;
        
        if (operation == "==")
            type = kEqualOperation;
        if (operation == "!=")
            type = kNotEqualOperation;
        if (operation == "<=")
            type = kLessEqualOperation;
        if (operation == ">=")
            type = kGreaterEqualOperation;
        
        return Lexeme(type, "", line, column);
    }
}

Lexeme end_of_line(int line, int column)
{
    return Lexeme(kEndofLine, "", line, column);
}