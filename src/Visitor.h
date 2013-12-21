//
//  Visitor.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 15/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef PPInterpreter_Visitor_h
#define PPInterpreter_Visitor_h

class Program;
class Function;
class Constant;
class Variable;
class AssignmentInstruction;
class FunctionCallInstruction;
class ArithmeticOperationInstruction;
class ReadInstruction;
class PrintInstruction;
class ConditionalInstruction;
class IfBlock;
class WhileBlock;
class ReturnInstruction;
class InstructionBlock;

class Visitor
{
public:
    virtual int visit(Constant const&) = 0;
    virtual int visit(Variable const&) = 0;
    virtual int visit(Program const&) = 0;
    virtual int visit(Function const&) = 0;
    virtual int visit(AssignmentInstruction const&) = 0;
    virtual int visit(FunctionCallInstruction const&) = 0;
    virtual int visit(ArithmeticOperationInstruction const&) = 0;
    virtual int visit(ReadInstruction const&) = 0;
    virtual int visit(PrintInstruction const&) = 0;
    virtual int visit(ConditionalInstruction const&) = 0;
    virtual int visit(IfBlock const&) = 0;
    virtual int visit(WhileBlock const&) = 0;
    virtual int visit(ReturnInstruction const&) = 0;
    virtual int visit(InstructionBlock const&) = 0;
    
    virtual ~Visitor() {}
};

#endif
