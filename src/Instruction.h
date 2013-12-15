//
//  Instruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Instruction_h
#define PPInterpreter_Instruction_h

#include "Declarations.h"

class Instruction
{
public:
    Instruction(Instruction* parent): m_parent(parent), m_scope(0) {}
    virtual ~Instruction() {delete m_scope;}
    
    virtual int evaluate(arg_vector* args = 0) = 0;
    
    virtual bool is_returnable() const {return false;}
    
    var_scope const* scope() const {return m_scope;}
    
private:
    Instruction* m_parent;
    var_scope* m_scope;
};


#endif
