//
//  ArithmeticOperationInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_ArithmeticOperationInstruction_h
#define PPInterpreter_ArithmeticOperationInstruction_h

#include "Instruction.h"

enum ArithmeticOperation
{
    kAdd = 0,
    kSub,
    kMul,
    kDiv,
};

class ArithmeticOperationInstruction: public Instruction
{
public:
    ArithmeticOperationInstruction(int line,
                                   ArithmeticOperation operation,
                                   Instruction* left_operand,
                                   Instruction* right_operand):
    Instruction(line),
    m_operation(operation),
    m_left_operand(left_operand),
    m_right_operand(right_operand) {}
    
    ArithmeticOperation operation() const {return m_operation;}
    Instruction* left_operand() const {return m_left_operand;}
    Instruction* right_operand() const {return m_right_operand;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    ArithmeticOperation m_operation;
    Instruction* m_left_operand;
    Instruction* m_right_operand;
};

#endif
