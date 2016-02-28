/*
 * OperatorPlusConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/OperatorPlusConstruct.hpp
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

#ifndef OPERATORPLUSCONSTRUCT_HPP
#define OPERATORPLUSCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> operator_plus()
{
    SP<Construct> plus_constr(new Construct("Plus", TType::Operators::Plus, NType::Operators::Add));
    
    SP<ConstructTreeFormNode> plus_treeForm(new ConstructTreeFormNode("Plus"));
    
    plus_constr->treeForm = plus_treeForm;
    
    return plus_constr;
}


#endif /* OPERATORADDCONSTRUCT_HPP */

