//
//  LexerState.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__LexerState__
#define __PPInterpreter__LexerState__

#include "LexingAutomation.h"
#include "SymbolTypes.h"

class LexingAutomation;

class LexerState
{
public:
    virtual void next_state(LexingAutomation& automation, SymbolTypes lexeme_type) = 0;
    virtual ~LexerState() {}
};

#endif /* defined(__PPInterpreter__LexerState__) */
