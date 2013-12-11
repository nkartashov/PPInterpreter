//
//  ErrorHandler.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__ErrorHandler__
#define __PPInterpreter__ErrorHandler__

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class ErrorHandler
{
public:
    static void reportSyntaxError(int lineNumber);
    static void reportDivisionByZero(int lineNumber);
    static void reportUndefinedVariable(int lineNumber, string variableName);
    static void reportUndefinedFunction(int lineNumber, string functionName);
    static void reportArgumentsNumberMismatch(int lineNumber, string functionName);
private:
    ErrorHandler();
};

#endif /* defined(__PPInterpreter__ErrorHandler__) */
