/*
 * OperatorAssignConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/OperatorAssignConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing the assignment operator ("+")
 *
 *        Usage: Will be used in parser statements, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef OPERATORASSIGNCONSTRUCT_HPP
#define OPERATORASSIGNCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> operator_assign()
{
    SP<Construct> assign_constr(new Construct("Operator - assign", TType::Operators::Equals, NType::Operators::Assign, 0, 0));

    SP<ConstructTreeFormNode> assign_treeForm(new ConstructTreeFormNode("Operator - assign"));
    
    assign_constr->treeForm = assign_treeForm;
    
    return assign_constr;
}


#endif /* OPERATOASSIGNCONSTRUCT_HPP */

