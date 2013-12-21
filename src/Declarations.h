//
//  Declarations.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Declarations_h
#define PPInterpreter_Declarations_h

#include <vector>
#include <iostream>

class std::shared_ptr;
class Instruction;
class Visitor;
class Program;
class LexerState;
class LexingAutomation;
class Error;

typedef std::shared_ptr<Instruction> instruction_ptr;
typedef std::shared_ptr<Program> program_ptr;
typedef std::shared_ptr<Visitor> visitor_ptr;
typedef std::vector<instruction_ptr> instructions;

#endif
