/*
 * EndStatement.hpp
 *
 * /KeyboardCodeLang/ParserStatements/EndStatement.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing the end ("\0") of the source code being compiled
 *
 *        Usage: Will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef ENDSTATEMENT_HPP
#define ENDSTATEMENT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;
using namespace parser;

void end_found(TokenManager& tm);

SP<Construct> endStatement()
{
    SP<Construct> end_constr(new Construct("End", TType::End, NType::End, end_found, 0));
    
    SP<ConstructTreeFormNode> end_treeForm(new ConstructTreeFormNode("End"));
    
    end_constr->treeForm = end_treeForm;
    
    return end_constr;
}
        
void end_found(TokenManager& tm)
{
    tm.exit = true;
}

#endif /* ENDSTATEMENT_HPP */

