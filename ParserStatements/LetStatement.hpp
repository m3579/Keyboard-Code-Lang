/*
 * LetStatement.hpp
 *
 * /KeywordCodeLang/ParserStatement/LetStatement.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a "let" statement - a variable declaration
 *
 *        Usage: Will be used in the parser
 *
 *        Notes: 
 *
 */

#ifndef LETSTATEMENT_HPP
#define LETSTATEMENT_HPP

#include <Construct.hpp>

#include "ParserConstructs/KeywordLetConstruct.hpp"
#include "ParserConstructs/IdentifierConstruct.hpp"
#include "ParserConstructs/WhitespaceConstruct.hpp"
#include "ParserConstructs/OperatorAssignConstruct.hpp"
#include "ParserConstructs/ValueConstruct.hpp"

using namespace ast;

SP<Construct> letStatement()
{
    SP<Construct> whitespace_optional(whitespace());
    whitespace_optional->optional = true;
    
    std::vector<SP<Construct>> let_stmt_components {
        keyword_let(), whitespace(), identifier(), whitespace_optional, operator_assign(), whitespace_optional, value()
    };
    
    SP<Construct> let_stmt(new Construct("Let statement", let_stmt_components, 0, 0));
    
    SP<ConstructTreeFormNode> let_treeForm(new ConstructTreeFormNode("Operator - assign"));
    let_treeForm->subnode("Identifier");
    let_treeForm->subnode("Value");
    
    let_stmt->treeForm = let_treeForm;
    
    return let_stmt;
}

#endif /* LETSTATEMENT_HPP */

