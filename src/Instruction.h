//
//  Instruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Instruction_h
#define PPInterpreter_Instruction_h

class Visitor;

class Instruction
{
public:
    Instruction(int line): m_line(line) {}
    virtual ~Instruction() {}
    int line() const {return m_line;}
    virtual bool does_return() const {return false;}
    virtual int accept_visit(Visitor& visitor) = 0;
    
private:
    int m_line;
};

#endif
