/*
 * KeywordLetConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/KeywordLetConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing the "let" keyword
 *
 *        Usage: Will be used in the parser
 *
 *        Notes: 
 *
 */

#ifndef KEYWORDLETCONSTRUCT_HPP
#define KEYWORDLETCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> keyword_let()
{
    SP<Construct> let_constr(new Construct("Keyword - 'let'", TType::Keywords::Let, NType::NOT_USED_IN_AST, 0, 0));
    
    SP<ConstructTreeFormNode> let_treeForm(new ConstructTreeFormNode("Keyword - 'let'"));
    
    let_constr->treeForm = let_treeForm;
    
    return let_constr;
}


#endif /* KEYWORDLETCONSTRUCT_HPP */

