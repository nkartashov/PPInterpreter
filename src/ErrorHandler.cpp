//
//  ErrorHandler.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "ErrorHandler.h"


void ErrorHandler::reportSyntaxError(int lineNumber)
{
    cout << "line " << lineNumber << ": syntax error." << endl;
}

void ErrorHandler::reportDivisionByZero(int lineNumber)
{
    cout << "line " << lineNumber << ": division by zero." << endl;
}

void reportUndefinedVariable(int lineNumber, string variableName)
{
    cout << "line " << lineNumber << ": undefined variable " << variableName << "." << endl;
}

void reportUndefinedFunction(int lineNumber, string functionName)
{
    cout << "line " << lineNumber << ": undefined function " << functionName << "." << endl;
}

void reportArgumentsNumberMismatch(int lineNumber, string functionName)
{
    cout << "line " << lineNumber << ": arguments number mismatch " << functionName << "." << endl;
}