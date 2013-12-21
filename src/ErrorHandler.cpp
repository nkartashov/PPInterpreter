//
//  ErrorHandler.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <iostream>

#include "ErrorHandler.h"

using std::cout;
using std::endl;


bool ErrorHandler::m_ok = true;

void ErrorHandler::report_syntax_error(int line_number)
{
    m_ok = false;
    cout << "line " << line_number << ": syntax error." << endl;
}

void ErrorHandler::report_division_by_zero(int line_number)
{
    m_ok = false;
    cout << "line " << line_number << ": division by zero." << endl;
}

void ErrorHandler::report_undefined_variable(int line_number, string variable_name)
{
    m_ok = false;
    cout << "line " << line_number << ": undefined variable " << variable_name << "." << endl;
}

void ErrorHandler::report_undefined_function(int line_number, string function_name)
{
    m_ok = false;
    cout << "line " << line_number << ": undefined function " << function_name << "." << endl;
}

void ErrorHandler::report_arguments_number_mismatch(int line_number, string function_name)
{
    m_ok = false;
    cout << "line " << line_number << ": arguments number mismatch " << function_name << "." << endl;
}