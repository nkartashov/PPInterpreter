//
//  ReadInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_ReadInstruction_h
#define PPInterpreter_ReadInstruction_h

#include <string>

#include "Instruction.h"

using std::string;

class ReadInstruction: public Instruction
{
public:
    ReadInstruction(int line, string const& variable): Instruction(line), m_variable(variable) {}
    
    string const& variable() const {return m_variable;}
    
    int accept_visit(Visitor& visitor) {return visitor.visit(*this);}
    
private:
    string m_variable;
};

#endif
