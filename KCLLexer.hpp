/*
 * KCLLexer.hpp
 *
 * /KeyboardCodeLang/KCLLexer.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 23, 20s16
 *
 *      Purpose: The lexer for Keyboard Code Lang code. This file contains
 *              a getLexer function that is invoked whenever a lexer is needed.
 *              It creates a lexer with the correct "test"s for Keyboard Code
 *              Lang.
 *
 *        Usage: Use the getLexer function to get a lexer whenever needed for
 *              the given source code.
 *
 *        Notes: 
 *
 */

#ifndef KCLLEXER_HPP
#define KCLLEXER_HPP

#include <iostream>
#include <string>
#include <map>

#include <Lexer.hpp>

#include "LexerTests/EndTest.hpp"
#include "LexerTests/IdentifierTest.hpp"
#include "LexerTests/KeywordTest.hpp"
#include "LexerTests/NumberTest.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;



std::map<std::string, std::string> textToTTypeMap;
void populateTextToTTypeMap();


/**
 * Creates a lexer that is configured to lex (convert code into a series of
 * tokens) the given source code.
 * 
 * @param source The source code to return a lexer of
 * @return A lexer configured to lex the given source code
 */
Lexer getLexer(std::string source)
{
    Lexer lexr(source);
    
    populateTextToTTypeMap();
    
    // Identifier
    addIdentifierTest(lexr);
    
    // Keywords
    addKeywordTest(lexr);
    
    // Number
    addNumberTest(lexr);
    
    // Space
    addSpaceTest(lexr);
    
    // End
    addEndTest(lexr);
    
    return lexr;
}


void populateTextToTTypeMap()
{
    textToTTypeMap["write"] = TType::Keywords::Write;
    textToTTypeMap["let"] = TType::Keywords::Let;
}


#endif /* KCLLEXER_HPP */

