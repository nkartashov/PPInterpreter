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

vector<Lexeme> Lexer::get_result()
{
    return m_automation->result();
}