//
//  PrintInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_PrintInstruction_h
#define PPInterpreter_PrintInstruction_h

#include "Instruction.h"

class PrintInstruction: public Instruction
{
public:
    PrintInstruction(int line, Instruction* expression): Instruction(line), m_expression(expression) {}
    
    Instruction const* expression() const {return m_expression;}
    
    int accept_visit(Visitor& visitor) {return visitor.visit(*this);}
    
private:
    Instruction* m_expression;
};

#endif
