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
               instructions const& block,
               instruction_ptr condition):
    InstructionBlock(line, block),
    m_condition(condition)
    {}
    
    instruction_ptr condition() const {return m_condition;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    instruction_ptr m_condition;
};

#endif
