//
//  Lexeme.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 11/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__Lexeme__
#define __PPInterpreter__Lexeme__

#include <string>

#include "LexemeTypes.h"

using std::string;

class Lexeme
{
public:
    Lexeme(LexemeTypes type, string value, int line, int column):
    m_type(type),
    m_value(value),
    m_line(line),
    m_column(column)
    {}

    LexemeTypes type() const {return m_type;}
    string value() const {return m_value;}
    int line() const {return m_line;}
    int column() const {return m_column;}

private:
    LexemeTypes m_type;
    string m_value;
    int m_line;
    int m_column;
};

#endif /* defined(__PPInterpreter__Lexeme__) */
