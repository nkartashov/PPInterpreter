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
    if (argc != 2)
    {
        cout << "Arguments number mismatch." << endl;
        cout << "Aborting ..." << endl;
        return 1;
    }
    string code_file_path = argv[1];
    shared_ptr<ifstream> input_stream(new ifstream(code_file_path));
    
    if (!*input_stream)
    {
        cout << "File " << code_file_path << " not found." << endl;
        cout << "Aborting..." << endl;
        return 2;
    }

    long file_length = 0;
    input_stream->seekg(0, input_stream->end);
    file_length = input_stream->tellg();
    input_stream->seekg(0, input_stream->beg);
    if (file_length == 0)
    {
        cout << "Empty code file " << code_file_path << endl;
        cout << "Nothing to do..." << endl;
        return 3;
    }
    
    Lexer lexer(input_stream);
    lexer.tokenize();
    
    if (!ErrorHandler::is_ok())
    {
//        cout << "Lexing error in file " << code_file_path << endl;
//        cout << "Aborting..." << endl;
        return 4;
    }
    
    vector<Lexeme> lexemes = lexer.get_result();
    
    Parser parser(lexemes);
    
    if (!ErrorHandler::is_ok())
    {
//        cout << "Parsing error in file " << code_file_path << endl;
//        cout << "Aborting..." << endl;
        return 5;
    }

    shared_ptr<Program> program = parser.get_parsed_program();
    Evaluator eval(*program);
    
    eval.execute_program();
    
    if (!ErrorHandler::is_ok())
    {
//        cout << "Evaluation error in file " << code_file_path << endl;
//        cout << "Aborting..." << endl;
        return 6;
    }
    
    return 0;
}

