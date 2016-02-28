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

using namespace lexer;
using namespace scanner;
using namespace token;

// This map is declared and populated in the global scope in this file
// because multiple files use it
std::map<std::string, std::string> textToTTypeMap;
void populateTextToTTypeMap();

// I include these files (the tests) after declaring textToTTypeMap because they use it
// and throw errors if they cannot find it
#include "LexerTests/EndTest.hpp"
#include "LexerTests/IdentifierTest.hpp"
#include "LexerTests/KeywordTest.hpp"
#include "LexerTests/NumberTest.hpp"
#include "LexerTests/StringTest.hpp"
#include "LexerTests/OperatorTest.hpp"
#include "LexerTests/SpaceTest.hpp"

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
    
    std::cout << "Creating lexer...\n\n";
    
    populateTextToTTypeMap();
    
    // Add tests to the lexer
    
    // Identifiers
    addIdentifierTest(lexr);
    
    // Keywords
    addKeywordTest(lexr);
    
    // Numbers
    addNumberTest(lexr);
    
    // Strings
    addStringTest(lexr);
    
    // Operators
    addOperatorTest(lexr);
    
    // Spaces
    addSpaceTest(lexr);
    
    // End ("\0")
    addEndTest(lexr);
    
    return lexr;
}


void populateTextToTTypeMap()
{
    textToTTypeMap["write"] = TType::Keywords::Write;
    textToTTypeMap["let"] = TType::Keywords::Let;
}


#endif /* KCLLEXER_HPP */

