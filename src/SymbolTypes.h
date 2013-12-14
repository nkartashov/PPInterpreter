//
//  SymbolTypes.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_SymbolTypes_h
#define PPInterpreter_SymbolTypes_h

#include <cctype>

enum SymbolTypes
{
    kUnknownType = -1,
    kLetter,
    kUnderscore,
    kDigit,
    kOperationSymbol,
    kSeparator,
    kHashSymbol,
    kLinefeed,
    kWhitespace
};

SymbolTypes determine_symbol_type(char symbol);

#endif
