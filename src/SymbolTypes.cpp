//
//  SymbolTypes.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 14/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "SymbolTypes.h"

SymbolTypes determine_symbol_type(char symbol)
{
    if (isalpha(symbol))
        return kLetter;
    
    if (isdigit(symbol))
        return kDigit;
    
    if (symbol == '\n')
        return kLinefeed;
    
    if (isspace(symbol))
        return kWhitespace;
    
    switch (symbol)
    {
        case '_':
            return kUnderscore;
            
        case '+':
        case '-':
        case '/':
        case '*':
        case '<':
        case '>':
        case '=':
        case '!':
            return kOperationSymbol;
            
        case ',':
        case '(':
        case ')':
        case ':':
            return kSeparator;
            
        case '#':
            return kHashSymbol;
            
        default:
            return kUnknownType;
    }
}