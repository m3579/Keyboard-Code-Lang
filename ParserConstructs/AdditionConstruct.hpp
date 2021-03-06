/*
 * AdditionConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/AdditionConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing an addition operator and its operands (e.g. 1 + 2). This differs from the
 *              OperatorAddConstruct in that this contains both the operator and its operands, whereas the OperatorAddConstruct
 *              is just the operator.
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef ADDITIONCONSTRUCT_HPP
#define ADDITIONCONSTRUCT_HPP

#include <Construct.hpp>

#include "OperatorAddConstruct.hpp"
#include "ValueConstruct.hpp"

using namespace ast;

SP<Construct> value();

SP<Construct> addition()
{   
    // I make links here to the value construct to avoid a circular reference
    // of Value->Expression->Addition->Value
    SP<Construct> operand1(new Construct(value));
    operand1->name = "Operand 1";
    
    SP<Construct> operand2(new Construct(value));
    operand2->name = "Operand 2";
    
    std::vector<SP<Construct>> addition_constr_components {
        operand1, operator_add(), operand2
    };
    
    SP<Construct> addition_constr(new Construct("Plus", addition_constr_components, 0, 0));
    
    SP<ConstructTreeFormNode> addition_treeForm(new ConstructTreeFormNode("Add"));
    addition_treeForm->subnode("Operand 1");
    addition_treeForm->subnode("Operand 2");
    
    addition_constr->treeForm = addition_treeForm;
    
    return addition_constr;
}


#endif /* OPERATORADDCONSTRUCT_HPP */

