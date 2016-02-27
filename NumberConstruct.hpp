/*
 * NumberConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/NumberConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing an identifier in the source code being compiled
 *              // TODO: include information about 1) the token and what it will look for, and 2)
 *              // the treeForm
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef NUMBERCONSTRUCT_HPP
#define NUMBERCONSTRUCT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;

SP<Construct> number()()
{
    SP<Construct> number_constr(new Construct("Number", TType::Values::Number, NType::Values::Number, 0, 0));
    
    SP<ConstructTreeFormNode> number_treeForm(new ConstructTreeFormNode("Number"));
    number_constr->treeForm = number_treeForm;
    
    return number_constr;
}


#endif /* NUMBERCONSTRUCT_HPP */

