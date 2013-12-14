//
//  OperationState.cpp
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


void OperationState::next_state(LexingAutomation& automation, SymbolTypes symbol_type)
{
    switch (symbol_type)
    {
        case kLetter:
            automation.set_result(handle_operation(automation.get_buffer_prefix(), automation.line(), automation.column()));
            automation.set_buffer_to_last_char();
            automation.set_state(new AlphanumericState());
            break;
        case kDigit:
            automation.set_result(handle_operation(automation.get_buffer_prefix(), automation.line(), automation.column()));
            automation.set_buffer_to_last_char();
            automation.set_state(new NumericState());
            break;
            
        case kOperationSymbol:
            break;
            
        case kSeparator:
            {
                automation.set_result(handle_operation(automation.get_buffer_prefix(), automation.line(), automation.column()));
                string buffer = automation.buffer();
                char lexeme_symbol = buffer[buffer.length() - 1];
                Lexeme result = handle_separator(lexeme_symbol, automation.line(), automation.column());
                automation.set_result(result);
                automation.clear_buffer();
                automation.set_state(new EmptyState());
            }
            break;
            
        case kWhitespace:
            {
                automation.set_result(handle_operation(automation.get_buffer_prefix(), automation.line(), automation.column()));
                automation.clear_buffer();
            }
            break;
            
        case kHashSymbol:
            {
                automation.set_result(handle_operation(automation.get_buffer_prefix(), automation.line(),automation.column()));
                automation.set_state(new CommentState());
            }
            break;
            
        default:
            automation.set_state(new ErrorState());
            break;
    }

}
