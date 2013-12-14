//
//  EmptyState.cpp
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

void EmptyState::next_state(LexingAutomation& automation, SymbolTypes symbol_type)
{
    switch (symbol_type)
    {
        case kLetter:
            automation.set_state(new AlphanumericState());
            break;
            
        case kDigit:
            automation.set_state(new NumericState());
            break;
            
        case kOperationSymbol:
            automation.set_state(new OperationState());
            break;
            
        case kSeparator:
            {
            	string buffer = automation.buffer();
                char lexeme_symbol = buffer[buffer.length() - 1];
                Lexeme result = handle_separator(lexeme_symbol, automation.line(), automation.column());
                automation.set_result(result);
                automation.set_state(new EmptyState());
            }
            break;
            
        case kLinefeed:
            automation.set_result(end_of_line(automation.line(), automation.column()));
            break;
            
        case kWhitespace:
            if (automation.buffer().length() != 1)
                automation.set_state(new ErrorState());
            else
                automation.clear_buffer();
            break;
            
        case kHashSymbol:
            automation.set_state(new CommentState());
            break;
            
        default:
            automation.set_state(new ErrorState());
            break;
    }
    
}
