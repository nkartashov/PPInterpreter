//
//  Lexer.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <string>

#include "ErrorHandler.h"
#include "Lexer.h"

Lexer::Lexer(istream* input_stream):
m_stream(input_stream),
m_automation(new LexingAutomation())
{
    
}

Lexer::~Lexer()
{
    delete m_automation;
}

void Lexer::tokenize()
{
    int line_number = -1;
    string line;
    while (true)
    {
        getline(*m_stream, line);
        if (!*m_stream)
            break;
        ++line_number;
        m_automation->next_line();
        for (size_t i = 0; i < line.length(); ++i)
        {
            m_automation->next_symbol(line[i]);
        }
        
        // Insert newline symbol to separate the lines
        m_automation->next_symbol('\n');
        if (!m_automation->is_good())
        {
            report_syntax_error(m_automation->line());
            return;
        }
    }
}

vector<Lexeme> Lexer::clean_result_stream(vector<Lexeme> result)
{
    vector<Lexeme> clean_result;
    
    size_t i = 0;
    
    while (i < result.size())
    {
        clean_result.push_back(result[i]);
        if (result[i].type() == kEndofLine)
        {
            ++i;
            while (i < result.size()  && result[i].type() == kEndofLine) {++i;}
        }
        else
            ++i;
    }
    
    return clean_result;
}

vector<Lexeme> Lexer::get_result()
{
    vector<Lexeme> result = m_automation->result();
    return clean_result_stream(result);
}

