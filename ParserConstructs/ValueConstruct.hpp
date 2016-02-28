/*
 * ValueConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/ValueConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a value in the source code being compiled
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef VALUECONSTRUCT_HPP
#define VALUECONSTRUCT_HPP

#include <Construct.hpp>

#include "NumberConstruct.hpp"
#include "IdentifierConstruct.hpp"
#include "StringConstruct.hpp"
#include "ExpressionConstruct.hpp"

using namespace ast;

SP<Construct> value()
{
    // I make a link to the expression to avoid a circular reference of
    // Value->Expression->Addition->Value
    SP<Construct> link_to_expression(new Construct(expression));
    
    // TODO: change from identifier() to variable(), function(), etc.
    // or put it in expression()
    std::vector<SP<Construct>> value_possible_constructs {
        number(), string(), identifier(), link_to_expression
    };
    
    SP<Construct> value_constr(new Construct(value_possible_constructs, "Value", 0, 0));
    
    SP<ConstructTreeFormNode> value_treeForm(new ConstructTreeFormNode("Value"));
    value_constr->treeForm = value_treeForm;
    
    return value_constr;
}

#endif /* VALUECONSTRUCT_HPP */

