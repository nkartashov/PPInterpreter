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
    PrintInstruction(int line, Instruction* expression): Instruction(line), m_expression(expression) {}
    
    Instruction const* expression() const {return m_expression;}
    
    int accept_visit(Visitor& visitor) {return visitor.visit(*this);}
    
private:
    Instruction* m_expression;
};


#endif
