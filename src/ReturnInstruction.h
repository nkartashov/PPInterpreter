//
//  ReturnInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_ReturnInstruction_h
#define PPInterpreter_ReturnInstruction_h

#include "Instruction.h"

class ReturnInstruction: public Instruction
{
public:
    ReturnInstruction(int line, instruction_ptr expression):
    Instruction(line),
    m_expression(expression) {}
    
    instruction_ptr expression() const {return m_expression;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    instruction_ptr m_expression;
};


#endif
