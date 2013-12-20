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
#include <string>

#include "Declarations.h"

using std::vector;
using std::string;

class Lexeme;
enum LexemeTypes;


class Parser
{
public:
    Parser(vector<Lexeme>& lexemes);
    
    Lexeme const& current_lexeme();
    Lexeme const& next_lexeme();

    bool match_current_lexeme(LexemeTypes type);
    
    bool match_current_lexeme_simple_arithmetic();
    bool match_current_lexeme_complex_arithmetic();
    bool match_current_lexeme_logic();

    void next_line();
    
    void start();
    int end();
    
    void save();
    void restore();
    
    bool finished();
    
    bool is_good();
    
    program_ptr get_parsed_program() {return m_program;}
    
private:
    program_ptr parse_program();
    instruction_ptr parse_instruction();
    instruction_ptr parse_function_definition();
    instruction_ptr parse_assignment();
    instruction_ptr parse_constant();
    instruction_ptr parse_variable();
    instruction_ptr parse_function_call();
    instruction_ptr parse_expression();
    instruction_ptr parse_condition();
    instruction_ptr parse_read();
    instruction_ptr parse_term();
    instruction_ptr parse_value();
    instruction_ptr parse_print();
    instruction_ptr parse_if_block();
    instruction_ptr parse_while_block();
    instruction_ptr parse_return();
    
    bool match_lexeme_simple_arithmetic(Lexeme);
    bool match_lexeme_complex_arithmetic(Lexeme);
    bool match_lexeme_logic(Lexeme);
    
    bool match_lexeme(LexemeTypes type, Lexeme lexeme);
    
    int parse_number(string);
    
    int m_current_lexeme_index;
    int m_buf_lexeme_index;
    int m_start_line;
    const vector<Lexeme>& m_lexemes;
    bool m_good;
    program_ptr m_program;
};

#endif /* defined(__PPInterpreter__Parser__) */
