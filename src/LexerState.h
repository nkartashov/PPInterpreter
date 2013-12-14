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

enum LexingAutomationStates
{
    kErrorState = -1,
    kOKState
};

class LexerState
{
public:
    virtual void next_state(LexingAutomation& automation, SymbolTypes lexeme_type) = 0;
    virtual LexingAutomationStates get_is_good_state() {return kOKState;}
    virtual ~LexerState() {}
};

#endif /* defined(__PPInterpreter__LexerState__) */
