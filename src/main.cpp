//
//  main.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 10/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using std::ifstream;
using std::istream;
using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::shared_ptr;

using namespace std;

#include "Lexer.h"
#include "Parser.h"
#include "Evaluator.h"
#include "Lexeme.h"
#include "ErrorHandler.h"

int main(int argc, const char* argv[])
{
//    if (argc < 2)
//    {
//        cout << "Not enough arguments" << endl;
//        cout << "Aborting ..." << endl;
//        return 1;
//    }
//    string code_file_path = argv[1];
//    string code_file_path = "simple_instruction.pp";
//    string code_file_path = "fib1.pp";
//    string code_file_path = "fib2.pp";
//    string code_file_path = "comment_test.pp";
//    string code_file_path = "syntax_error_test.pp";
//    string code_file_path = "syntax_error_test2.pp";
//    string code_file_path = "multiline_code_test.pp";
//    string code_file_path = "empty_function_test.pp";
//    string code_file_path = "assignment_test.pp";
//    string code_file_path = "complex_assignment_test_no_brackets.pp";
//    string code_file_path = "complex_assignment_test_with_brackets.pp";
//    string code_file_path = "assignment_with_functions.pp";
//    string code_file_path = "simple_a+b.pp";
//    string code_file_path = "a_plus_b_via_func.pp";
//    string code_file_path = "rootN.pp";
//    string code_file_path = "fib.pp";
    string code_file_path = "one_more_fib.pp";
    ifstream* input_stream = new ifstream(code_file_path);
    
    if (!*input_stream)
    {
        cout << "File " << code_file_path << " not found" << endl;
        cout << "Aborting..." << endl;
        return 2;
    }

    long file_length = 0;
    input_stream->seekg(0, input_stream->end);
    file_length = input_stream->tellg();
    input_stream->seekg(0, input_stream->beg);
    if (file_length == 0)
    {
        cout << "Empty code file" << endl;
        cout << "Nothing to do..." << endl;
        input_stream->close();
        return 3;
    }
    
    Lexer lexer(input_stream);
    lexer.tokenize();
    
    vector<Lexeme> lol = lexer.get_result();
    
    Parser parser(lol);
    
    shared_ptr<Program> program = parser.get_parsed_program();
    Evaluator eval(*program);
    
    eval.execute_program();
    
    input_stream->close();
    return 0;
}

