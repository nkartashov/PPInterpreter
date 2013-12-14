//
//  EmptyState.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__EmptyState__
#define __PPInterpreter__EmptyState__

#include "LexerState.h"
#include "SymbolTypes.h"

class LexingAutomation;

class EmptyState: public LexerState
{
public:
    void next_state(LexingAutomation& automation, SymbolTypes symbol_type);
};

#endif /* defined(__PPInterpreter__EmptyState__) */
