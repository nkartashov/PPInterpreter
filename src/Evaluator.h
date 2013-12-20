//
//  Evaluator.h
//  PPInterpreter
//
//  Created by Nikita Kartashov on 20/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __PPInterpreter__Evaluator__
#define __PPInterpreter__Evaluator__

#include <stack>

#include "Visitor.h"
#include "Declarations.h"

using std::stack;

typedef std::map<std::string, int> variable_scope;
typedef std::map<std::string, Function const*> function_scope;
typedef std::pair<std::string, int> variable_instance;

class Evaluator: public Visitor
{
public:
    Evaluator(Program const& program);
    
    int visit(Constant const&);
    int visit(Variable const&);
    int visit(Program const&);
    int visit(Function const&);
    int visit(AssignmentInstruction const&);
    int visit(FunctionCallInstruction const&);
    int visit(ArithmeticOperationInstruction const&);
    int visit(ReadInstruction const&);
    int visit(PrintInstruction const&);
    int visit(ConditionalInstruction const&);
    int visit(IfBlock const&);
    int visit(WhileBlock const&);
    int visit(ReturnInstruction const&);
    int visit(InstructionBlock const&);
    
    variable_scope& scope();
    
    
    void in_function(variable_scope&);
    void out_function();
    
    void set_return_value(int value);
    bool has_returned() {return m_has_returned;}
    int on_return();
    
private:
    bool m_has_returned;
    int m_result;
    
    function_scope m_function_scope;
    stack<variable_scope> m_variable_scopes;
};

#endif /* defined(__PPInterpreter__Evaluator__) */
