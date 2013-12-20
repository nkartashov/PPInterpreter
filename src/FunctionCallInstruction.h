//
//  FunctionCallInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_FunctionCallInstruction_h
#define PPInterpreter_FunctionCallInstruction_h

#include <string>

#include "Instruction.h"
#include "Declarations.h"

using std::string;

class FunctionCallInstruction: public Instruction
{
public:
    FunctionCallInstruction(int line, instructions arguments):
    Instruction(line),
    m_arguments(arguments) {}
    
    string const& name() const {return m_name;}
    instructions const& arguments() {return m_arguments;}
    
    int accept_visit(Visitor* visitor) {return visitor->visit(*this);}
    
private:
    string m_name;
    instructions m_arguments;
};

#endif
