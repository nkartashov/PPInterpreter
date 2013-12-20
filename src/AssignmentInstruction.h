//
//  AssignmentInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_AssignmentInstruction_h
#define PPInterpreter_AssignmentInstruction_h

#include <string>
#include <vector>

#include "Instruction.h"

using std::string;
using std::vector;

class AssignmentInstruction: public Instruction
{
public:
    AssignmentInstruction(int line,
                          string const& name,
                          instruction_ptr expression):
    Instruction(line),
    m_name(name),
    m_expression(expression) {}
    
    string const& name() const {return m_name;}
    instruction_ptr const expression() const {return m_expression;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    string m_name;
    instruction_ptr m_expression;
};


#endif
