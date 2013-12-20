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

using std::vector;
using std::string;

class Lexeme;
enum LexemeTypes;
class Instruction;

class Parser
{
public:
    Parser(vector<Lexeme>& lexemes);
    
    Lexeme const& current_lexeme();
    Lexeme const& peek_next_lexeme();
    Lexeme const& next_lexeme();
    bool match_lexeme(LexemeTypes type, Lexeme lexeme);
    bool match_current_lexeme(LexemeTypes type);
    bool match_lexeme_simple_arithmetic(Lexeme);
    bool match_lexeme_complex_arithmetic(Lexeme);
    bool match_lexeme_logic(Lexeme);
    
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
    
private:
    Instruction* parse_program();
    Instruction* parse_instruction();
    Instruction* parse_function_definition();
    Instruction* parse_assignment();
    Instruction* parse_constant();
    Instruction* parse_variable();
    Instruction* parse_function_call();
    Instruction* parse_expression();
    Instruction* parse_condition();
    Instruction* parse_read();
    Instruction* parse_term();
    Instruction* parse_value();
    Instruction* parse_print();
    Instruction* parse_if_block();
    Instruction* parse_while_block();
    Instruction* parse_return();
    
    int parse_number(string);
    
    int m_current_lexeme_index;
    int m_buf_lexeme_index;
    int m_start_line;
    const vector<Lexeme>& m_lexemes;
    bool m_good;
    Instruction* m_program;
};

#endif /* defined(__PPInterpreter__Parser__) */
