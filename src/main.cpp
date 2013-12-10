//
//  main.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 10/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <memory>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::shared_ptr;

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        cout << "Not enough arguments" << endl;
        cout << "Aborting ..." << endl;
        return 1;
    }
    string code_file_path = argv[1];
    shared_ptr<ifstream> input_stream(new ifstream(code_file_path, ios::in));
    
    long file_length = 0;
    input_stream->seekg(0, ios::end);
    file_length = input_stream->tellg();
    input_stream->seekg(0, ios::beg);
    if (file_length == 0)
    {
        cout << "Empty code file" << endl;
        cout << "Aborting ..." << endl;
        return 2;
    }
    
    return 0;
}

