//
//  Variable.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Variable_h
#define PPInterpreter_Variable_h

#include <string>

#include "Instruction.h"

using std::string;

class Variable: public Instruction
{
public:
    Variable(int line, string const& name): Instruction(line), m_name(name) {}
    
    string const& name() const {return m_name;}
    
    int accept_visit(Visitor* visitor) {return visitor->visit(*this);}
    
private:
    string m_name;
    
};

#endif
