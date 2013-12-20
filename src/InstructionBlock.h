//
//  InstructionBlock.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_InstructionBlock_h
#define PPInterpreter_InstructionBlock_h

#include "Instruction.h"

class InstructionBlock: public Instruction
{
public:
    InstructionBlock(int line, instructions const& block):
    Instruction(line),
    m_block(block) {}
    
    instructions const& block() const {return m_block;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    instructions m_block;
};


#endif
