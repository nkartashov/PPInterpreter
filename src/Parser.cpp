//
//  Parser.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "Parser.h"
#include "ErrorHandler.h"

#include "Lexeme.h"

Parser::Parser(vector<Lexeme>& lexemes): m_lexemes(lexemes), m_current_lexeme_index(0)
{
}

Lexeme const& Parser::current_lexeme()
{
    return m_lexemes[m_current_lexeme_index];
}

Lexeme const& Parser::next_lexeme()
{
    if (m_current_lexeme_index + 1 < m_lexemes.size())
        return m_lexemes[++m_current_lexeme_index];
    
    m_good = false;
    report_syntax_error(m_lexemes[m_current_lexeme_index].line());
    return m_lexemes[m_current_lexeme_index];
}