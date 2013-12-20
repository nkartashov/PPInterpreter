//
//  Constant.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Constant_h
#define PPInterpreter_Constant_h

#include "Instruction.h"

class Constant: public Instruction
{
public:
    Constant(int line, int value): Instruction(line), m_value(value) {}
    
    int value() const {return m_value;}
    
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    int m_value;
};

#endif
