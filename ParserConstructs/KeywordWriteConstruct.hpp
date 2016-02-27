/*
 * KeywordWriteConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/KeywordWriteConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing the keyword "write" in the source code being compiled
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef KEYWORDWRITECONSTRUCT_HPP
#define KEYWORDWRITECONSTRUCT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;

SP<Construct> keyword_write()
{
    SP<Construct> write_constr(new Construct("Keyword - 'write'", TType::Keywords::Write, NType::FunctionCall, 0, 0));
    
    SP<ConstructTreeFormNode> write_treeForm(new ConstructTreeFormNode("Keyword - 'write'"));
    write_constr->treeForm = write_treeForm;
    
    return write_constr;
}


#endif /* KEYWORDWRITECONSTRUCT_HPP */

