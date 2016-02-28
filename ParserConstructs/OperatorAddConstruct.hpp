/*
 * OperatorAddConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/OperatorAddConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing an addition operator ("+") in the source code. This differs from
 *              the addition construct in that this is just the operator, whereas the addition construct is both the
 *              operator and the operands.
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef OPERATORADDCONSTRUCT_HPP
#define OPERATORADDCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> operator_add()
{
    SP<Construct> add_constr(new Construct("Operator - add", TType::Operators::Plus, NType::Operators::Add, 0, 0));
    
    SP<ConstructTreeFormNode> add_treeForm(new ConstructTreeFormNode("Add"));
    
    add_constr->treeForm = add_treeForm;
    
    return add_constr;
}


#endif /* OPERATORADDCONSTRUCT_HPP */

