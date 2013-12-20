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
                                   instruction_ptr left_operand,
                                   instruction_ptr right_operand):
    Instruction(line),
    m_operation(operation),
    m_left_operand(left_operand),
    m_right_operand(right_operand) {}
    
    ArithmeticOperation operation() const {return m_operation;}
    instruction_ptr left_operand() const {return m_left_operand;}
    instruction_ptr right_operand() const {return m_right_operand;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    ArithmeticOperation m_operation;
    instruction_ptr m_left_operand;
    instruction_ptr m_right_operand;
};

#endif
