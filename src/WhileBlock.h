//
//  WhileBlock.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_WhileBlock_h
#define PPInterpreter_WhileBlock_h

#include "InstructionBlock.h"

class WhileBlock: public InstructionBlock
{
public:
    WhileBlock(int line,
            Instruction const* condition,
            instructions const& block):
    Instruction(line),
    m_condition(condition),
    m_block(block) {}
    
    Instruction const* condition() {return m_condition;}
    instructions const& block() {return m_block;}
    
private:
    Instruction* m_condition;
    instructions m_block;
};

#endif
