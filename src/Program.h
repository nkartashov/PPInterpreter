//
//  Program.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Program_h
#define PPInterpreter_Program_h

#include "InstructionBlock.h"
#include "Visitor.h"

class Program: public InstructionBlock
{
public:
    Program(int line, instructions const& body, instructions& functions): InstructionBlock(line, body), m_functions(functions) {}
    instructions const& functions() const {return m_functions;}
    int accept_visit(Visitor* visitor) const {return visitor->visit(*this);}
    
private:
    instructions m_functions;
};

#endif
