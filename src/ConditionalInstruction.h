//
//  ConditionalInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_ConditionalInstruction_h
#define PPInterpreter_ConditionalInstruction_h

#include "Instruction.h"

enum LogicalOperation
{
    Equal = 0,
    NotEqual,
    Less,
    Greater,
    LessEqual,
    GreaterEqual
};

class ConditionalInstruction: public Instruction
{
public:
    ConditionalInstruction(int line,
                           LogicalOperation operation,
                           Instruction* left_operand,
                           Instruction* right_operand):
    Instruction(line),
    m_operation(operation),
    m_left_operand(left_operand),
    m_right_operand(right_operand) {}
    
    LogicalOperation operation() const {return m_operation;}
    Instruction const* left_operand() const {return m_left_operand;}
    Instruction const* right_operand() const {return m_right_operand;}
    
private:
    LogicalOperation m_operation;
    Instruction* m_left_operand;
    Instruction* m_right_operand;
};

#endif
