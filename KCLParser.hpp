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
                                    NType::Testing::LetterA, 0, 0));
    
    SP<ConstructTreeFormNode> letter_a_treeForm(new ConstructTreeFormNode("Letter A"));
    letter_a_constr->treeForm = letter_a_treeForm;
    
    //parser.addConstruct(letter_a_constr);
    
    // END TESTING
    
    // Identifier
    SP<Construct> identifier_constr(new Construct("Identifier", TType::Identifier, NType::Identifier, 0, 0));
    
    SP<ConstructTreeFormNode> identifier_treeForm(new ConstructTreeFormNode("Identifier"));
    identifier_constr->treeForm = identifier_treeForm;
    
    // Number
    SP<Construct> number_constr(new Construct("Number", TType::Values::Number, NType::Values::Number, 0, 0));
    
    SP<ConstructTreeFormNode> number_treeForm(new ConstructTreeFormNode("Number"));
    number_constr->treeForm = number_treeForm;
    
    // Value
    std::vector<TokenType> value_ttypes {
        TType::Values::Number
    };
    std::vector<NodeType> value_ntypes {
        NType::Values::Number
    };
    
    SP<Construct> value_constr(new Construct("Value", value_ttypes, value_ntypes, 0, 0));
    
    // Whitespace
    std::vector<TokenType> whitespace_ttypes {
        TType::Whitespace::Space
    };
    std::vector<NodeType> whitespace_ntypes {
        NType::NOT_USED_IN_AST
    };
    
    SP<Construct> whitespace_constr(new Construct("Whitespace", whitespace_ttypes, whitespace_ntypes, 0, 0));
    
    // Write keyword
    SP<Construct> write_constr(new Construct("Keyword - 'write'", TType::Keywords::Write, NType::FunctionCall, 0, 0));
    
    SP<ConstructTreeFormNode> write_treeForm(new ConstructTreeFormNode("Keyword - 'write'"));
    write_constr->treeForm = write_treeForm;
    
    // Write statement
    std::vector<SP<Construct>> write_stmt_components {
        write_constr, whitespace_constr, value_constr
    };
    SP<Construct> write_stmt_constr(new Construct("Write Statement", write_stmt_components, 0, 0));
    SP<ConstructTreeFormNode> write_stmt_treeForm(new ConstructTreeFormNode("Keyword - 'write'"));
    write_stmt_treeForm->subnode("Value");
    
    parser.addConstruct(write_stmt_constr);
    
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

