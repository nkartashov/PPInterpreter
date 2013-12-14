//
//  AlphanumericState.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__AlphanumericState__
#define __PPInterpreter__AlphanumericState__

#include "LexerState.h"
#include "SymbolTypes.h"

class AlphanumericState: public LexerState
{
public:
    void next_state(LexingAutomation& automation, SymbolTypes symbol_type);
};

#endif /* defined(__PPInterpreter__AlphanumericState__) */
