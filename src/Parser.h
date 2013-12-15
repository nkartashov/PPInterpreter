//
//  Parser.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__Parser__
#define __PPInterpreter__Parser__
#include <vector>

using std::vector;

class Lexeme;

class Parser
{
public:
    Parser(vector<Lexeme>& lexemes);
    
    Lexeme const& current_lexeme();
    Lexeme const& next_lexeme();
    
    bool is_good() {return m_good;}
    
private:
    
    int m_current_lexeme_index;
    const vector<Lexeme>& m_lexemes;
    bool m_good;
};

#endif /* defined(__PPInterpreter__Parser__) */
