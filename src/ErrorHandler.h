//
//  ErrorHandler.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__ErrorHandler__
#define __PPInterpreter__ErrorHandler__

#include <string>

using std::string;

void report_syntax_error(int line_number);
void report_division_by_zero(int line_number);
void report_undefined_variable(int line_number, string variable_name);
void report_undefined_function(int line_number, string function_name);
void report_arguments_number_mismatch(int line_number, string function_name);

#endif /* defined(__PPInterpreter__ErrorHandler__) */
