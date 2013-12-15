//
//  Lexer.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__Lexer__
#define __PPInterpreter__Lexer__

#include <vector>
#include <iostream>

#include "Lexeme.h"
#include "LexingAutomation.h"

using std::vector;
using std::istream;

class Lexer
{
public:
    Lexer(istream* input_stream);
    ~Lexer();
    
    void tokenize();
    vector<Lexeme> get_result();
    
private:
    vector<Lexeme> clean_result_stream(vector<Lexeme> result);
    
    istream* m_stream;
    LexingAutomation* m_automation;
};

#endif /* defined(__PPInterpreter__Lexer__) */
