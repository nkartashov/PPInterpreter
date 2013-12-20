//
//  Function.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Function_h
#define PPInterpreter_Function_h

#include <vector>
#include <string>

#include "InstructionBlock.h"

using std::vector;
using std::string;

class Function: public InstructionBlock
{
public:
    Function(int line, instructions const& block,
             string const& name,
             vector<string> const& arguments):
    InstructionBlock(line, block),
    m_name(name),
    m_arguments(arguments) {}
    
    string const& name() const {return m_name;}
    vector<string> const& arguments() const {return m_arguments;}
    
    bool does_return() const {return true;}
    
    int accept_visit(Visitor* visitor) {return visitor->visit(*this);}

private:
    string m_name;
    vector<string> m_arguments;
};

#endif
