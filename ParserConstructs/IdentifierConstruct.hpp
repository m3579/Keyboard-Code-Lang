/*
 * IdentifierConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/IdentifierConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing an identifier in the source code being compiled
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef IDENTIFIERCONSTRUCT_HPP
#define IDENTIFIERCONSTRUCT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;

SP<Construct> identifier()
{
    SP<Construct> identifier_constr(new Construct("Identifier", TType::Identifier, NType::Identifier, 0, 0));
    
    SP<ConstructTreeFormNode> identifier_treeForm(new ConstructTreeFormNode("Identifier"));
    identifier_constr->treeForm = identifier_treeForm;
    
    return identifier_constr;
}


#endif /* IDENTIFIERCONSTRUCT_HPP */

