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
    Program(int line, instructions const& block): InstructionBlock(line, block) {}
    int accept_visitor(Visitor& visitor) {return visitor.visit(*this);}
    
private:
};

#endif
