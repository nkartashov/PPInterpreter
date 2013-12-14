//
//  CommentState.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__CommentState__
#define __PPInterpreter__CommentState__

#include <iostream>

#include "LexerState.h"

class CommentState: public LexerState
{
public:
    void next_state(LexingAutomation& automation, SymbolTypes symbol_type);
};


#endif /* defined(__PPInterpreter__CommentState__) */
