//
//  AssignmentInstruction.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__AssignmentInstruction__
#define __PPInterpreter__AssignmentInstruction__

#include <string>

#include "Instruction.h"
#include "Declarations.h"

using std::string;

class AssignmentInstruction: public Instruction
{
public:
    AssignmentInstruction(Instruction* parent, string assignee);
    int evaluate (arg_vector* args);

private:
    string m_assignee;
    
};

#endif /* defined(__PPInterpreter__AssignmentInstruction__) */
