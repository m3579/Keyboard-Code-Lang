/*
 * WhitespaceConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/WhitespaceConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2015
 *
 *      Purpose: Creates a construct representing whitespace in the source code being compiled
 *
 *        Usage: Will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef WHITESPACECONSTRUCT_HPP
#define WHITESPACECONSTRUCT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;

SP<Construct> getWhitespaceConstruct()
{
    std::vector<TokenType> whitespace_ttypes {
        TType::Whitespace::Space
    };
    std::vector<NodeType> whitespace_ntypes {
        NType::NOT_USED_IN_AST
    };
    
    SP<Construct> whitespace_constr(new Construct("Whitespace", whitespace_ttypes, whitespace_ntypes, 0, 0));
    
    SP<ConstructTreeFormNode> whitespace_treeForm(new ConstructTreeFormNode("Whitespace"));
    whitespace_constr->treeForm = whitespace_treeForm;
    
    return whitespace_constr;
}


#endif /* WHITESPACECONSTRUCT_HPP */

