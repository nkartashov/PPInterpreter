//
//  ErrorState.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__ErrorState__
#define __PPInterpreter__ErrorState__

#include "LexerState.h"

class ErrorState: public LexerState
{
public:
    void next_state(LexingAutomation& automation, SymbolTypes symbol_type);
    virtual LexingAutomationStates get_is_good_state() {return kErrorState;}
};

#endif /* defined(__PPInterpreter__ErrorState__) */
