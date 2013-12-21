//
//  LexingAutomation.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__LexingAutomation__
#define __PPInterpreter__LexingAutomation__

#include <string>
#include <vector>

#include "Lexeme.h"

class LexerState;

using std::string;
using std::vector;

typedef std::shared_ptr<LexerState> state_ptr;

class LexerState;

class LexingAutomation
{
public:
    LexingAutomation();
    void set_state(state_ptr);
    void set_result(Lexeme);
    
    void set_buffer(string);
    void set_buffer_to_last_char();
    void clear_buffer();
    string get_buffer_prefix() const;
    
    void next_symbol(char symbol);
    void next_line();
    
    string const& buffer() const {return m_buffer;}
    int line() const {return m_line;}
    int column() const {return m_column;}
    vector<Lexeme> const& result() const {return m_result;}
    
private:
    LexingAutomation(LexingAutomation const&);
    LexingAutomation& operator=(LexingAutomation const&);
    
    int m_line;
    int m_column;
    string m_buffer;
    state_ptr m_state;
    vector<Lexeme> m_result;
};

#endif /* defined(__PPInterpreter__LexingAutomation__) */
