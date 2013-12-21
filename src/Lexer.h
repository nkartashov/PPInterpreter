//
//  Lexer.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__Lexer__
#define __PPInterpreter__Lexer__

#include <iostream>

#include "Lexeme.h"
#include "LexingAutomation.h"

typedef std::shared_ptr<std::istream> istream_ptr;
typedef std::shared_ptr<LexingAutomation> automation_ptr;

class Lexer
{
public:
    Lexer(istream_ptr input_stream);
    
    void tokenize();
    vector<Lexeme> get_result();
    
private:
    vector<Lexeme> clean_result_stream(vector<Lexeme> result);
    
    istream_ptr m_stream;
    automation_ptr m_automation;
};

#endif /* defined(__PPInterpreter__Lexer__) */
