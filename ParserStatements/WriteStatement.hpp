/*
 * WriteStatement.hpp
 *
 * /KeyboardCodeLang/ParserStatements/WriteStatement.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a "write" statement in the source code being compiled
 *
 *        Usage: Will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef WRITESTATEMENT_HPP
#define WRITESTATEMENT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

#include "ParserConstructs/KeywordWriteConstruct.hpp"
#include "ParserConstructs/WhitespaceConstruct.hpp"
#include "ParserConstructs/ValueConstruct.hpp"

using namespace ast;

SP<Construct> writeStatement()
{
    std::vector<SP<Construct>> write_stmt_components {
        keyword_write(), whitespace(), value()
    };
    
    SP<Construct> write_stmt(new Construct("Write statement", write_stmt_components, 0, 0));
    
    SP<ConstructTreeFormNode> write_treeForm(new ConstructTreeFormNode("Keyword - 'write'"));
    write_treeForm->subnode("Value");
    
    write_stmt->treeForm = write_treeForm;

    return write_stmt;
}


#endif /* WRITESTATEMENT_HPP */

