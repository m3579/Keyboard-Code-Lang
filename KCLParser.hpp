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
#include "NodeTypes.hpp"

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
    
    // TESTING
    
    // Letter A
    SP<Construct> letter_a_constr(new Construct("Letter A", TType::Testing::LetterA,
                                    NType::Testing::LetterA, 0, 0);
    
    SP<ConstructTreeFormNode> letter_a_treeForm(new ConstructTreeFormNode("Letter A"));
    letter_a_constr->treeForm = letter_a_treeForm;
    
    parser.addConstruct(letter_a_constr);
    
    // END TESTING
    
    // End
    SP<Construct> end_constr(new Construct("End", TType::End, NType::End, 
            [] (TokenManager& tm) { tm.exit = true; }, 0));
    
    SP<ConstructTreeFormNode> end_treeForm(new ConstructTreeFormNode("End"));
    end_constr->treeForm = end_treeForm;
    
    parser.addConstruct(end_constr);
    
    return parser;
}


#endif /* KCLPARSER_HPP */

