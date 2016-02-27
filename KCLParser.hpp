/*
 * KCLParser.hpp
 *
 * /KeyboardCodeLang/KCLParser.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 23, 2016
 *
 *      Purpose: The parser for KeyboardCodeLang code. It takes the tokens
 *              that it gets from the lexer and assembles them into a tree
 *              form (the Abstract Syntax Tree, or AST).
 *
 *        Usage: Use the getParser function to create a new parser configured
 *              to parse KCL code.
 *
 *        Notes: 
 *
 */

#ifndef KCLPARSER_HPP
#define KCLPARSER_HPP

#include <iostream>

#include <Parser.hpp>

#include "KCLLexer.hpp"

#include "ParserStatements/WriteStatement.hpp"

using namespace parser;
using namespace ast;

/**
 * Creates a parser that assembles an AST (Abstract Syntax Tree) from the
 * tokens produced by the given lexer.
 * 
 * @param lexr A lexer that will give the parser tokens to assemble into an AST.
 * @return A parser that will assemble the tokens that it gets from the given lexer.
 */
Parser getParser(Lexer lexr)
{
    Parser parser(lexr);
    
    // Write statement
    parser.addConstruct(writeStatement());
    
    // Let keyword
    SP<Construct> let_constr(new Construct("Keyword - 'let'", TType::Keywords::Let, NType::NOT_USED_IN_AST, 0, 0));
    
    SP<ConstructTreeFormNode> let_treeForm(new ConstructTreeFormNode("Keyword - 'let'"));
    let_constr->treeForm = let_treeForm;
    
    // End
    SP<Construct> end_constr(new Construct("End", TType::End, NType::End, 
            [] (TokenManager& tm) { tm.exit = true; }, 0));
    
    SP<ConstructTreeFormNode> end_treeForm(new ConstructTreeFormNode("End"));
    end_constr->treeForm = end_treeForm;
    
    parser.addConstruct(end_constr);
    
    return parser;
}


#endif /* KCLPARSER_HPP */

