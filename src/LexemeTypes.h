//
//  LexemeTypes.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__LexemeTypes__
#define __PPInterpreter__LexemeTypes__

#include <string>
#include <ctype.h>


using std::string;

class Lexeme;

enum LexemeTypes
{
    kUnknownLexeme = -1,
    kId,
    kNumber,
    kLeftBracket,
    kRightBracket,
    kComma,
    kColon,
    kEndofLine,
    kIfKeyword,
    kDefKeyword,
    kWhileKeyword,
    kReadKeyword,
    kPrintKeyword,
    kReturnKeyword,
    kEndKeyword,
    kAssignment,
    kLessOperation,
    kGreaterOperation,
    kLessEqualOperation,
    kGreaterEqualOperation,
    kEqualOperation,
    kNotEqualOperation,
    kAddition,
    kSubtraction,
    kDivision,
    kMultiplication
};

Lexeme handle_separator(char separator, int line, int column);
Lexeme handle_number(string number, int line, int column);
Lexeme handle_alphanumeric(string alphanumeric, int line, int column);
Lexeme handle_operation(string operation, int line, int column);
Lexeme end_of_line(int line, int column);

#endif /* defined(__PPInterpreter__LexemeTypes__) */
