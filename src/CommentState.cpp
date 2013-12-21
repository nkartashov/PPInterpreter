//
//  CommentState.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "Lexeme.h"
#include "LexemeTypes.h"

#include "EmptyState.h"
#include "AlphanumericState.h"
#include "NumericState.h"
#include "OperationState.h"
#include "ErrorState.h"
#include "CommentState.h"

void CommentState::next_state(LexingAutomation& automation, SymbolTypes symbol_type)
{
    switch (symbol_type)
    {
        case kLinefeed:
            {
                automation.set_result(end_of_line(automation.line(), automation.column()));
                automation.clear_buffer();
                automation.set_state(state_ptr(new EmptyState()));
            }
            break;
            
        default:
            automation.clear_buffer();
            break;
    }
}