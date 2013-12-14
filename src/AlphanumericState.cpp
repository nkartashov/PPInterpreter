//
//  AlphanumericState.cpp
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

void AlphanumericState::next_state(LexingAutomation &automation, SymbolTypes symbol_type)
{
    switch (symbol_type)
    {
        case kUnderscore:
        case kLetter:
        case kDigit:
            break;
            
        case kOperationSymbol:
            {
                automation.set_result(handle_alphanumeric(automation.get_buffer_prefix(), automation.line(), automation.column()));
                automation.set_buffer_to_last_char();
                automation.set_state(new OperationState());
            }
            break;
            
        case kSeparator:
            {
                automation.set_result(handle_alphanumeric(automation.get_buffer_prefix(), automation.line(), automation.column()));
                string buffer = automation.buffer();
                char lexeme_symbol = buffer[buffer.length() - 1];
                Lexeme result = handle_separator(lexeme_symbol, automation.line(), automation.column());
                automation.set_result(result);
                automation.clear_buffer();
                automation.set_state(new EmptyState());
            }
            break;
        
        case kLinefeed:
            {
                automation.set_result(handle_alphanumeric(automation.get_buffer_prefix(), automation.line(), automation.column()));
                automation.set_result(end_of_line(automation.line(), automation.column()));
                automation.clear_buffer();
                automation.set_state(new EmptyState());
            }
            
        case kWhitespace:
            {
                automation.set_result(handle_alphanumeric(automation.get_buffer_prefix(), automation.line(), automation.column()));
                automation.clear_buffer();
            }
            break;
            
        case kHashSymbol:
            {
                automation.set_result(handle_alphanumeric(automation.get_buffer_prefix(), automation.line(),automation.column()));
                automation.set_state(new CommentState());
            }
            break;
            
        default:
            automation.set_state(new ErrorState());
            break;
    }
}