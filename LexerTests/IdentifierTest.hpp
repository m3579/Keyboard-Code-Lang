/*
 * IdentifierTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/IdentifierTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds a test to the lexer for identifiers in the source code
 *              // TODO: define identifier
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef IDENTIFIERTEST_HPP
#define IDENTIFIERTEST_HPP

#include <Lexer.hpp>

#include "TokenTypes.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;


const std::string IDENTIFIER_START_CHARS = "abcdefghijklmnopqrstuvwxyzQBCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string IDENTIFIER_CHARS = IDENTIFIER_START_CHARS + "0123456789";

void addIdentifierTest(Lexer& lexr)
{
    lexr.addTest(
        [] (Scanner& sc) {
            char c = sc.getCurrentChar();
            if (IDENTIFIER_START_CHARS.find(c) != std::string::npos) {
                sc.startCountingMovements();
                
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while (IDENTIFIER_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                // If identifier is not in keyword-TokenType map
                // (hence, if identifier is not a keyword)
                if (textToTTypeMap.find(tokenString) == textToTTypeMap.end()) {
                    return Token(lineNumber, columnNumber, tokenString, TType::Identifier);
                }
                else {
                    // Move the scanner back to the beginning of the word
                    sc.reset();
                }
            }
            
            return Token();
        }
    );
}


#endif /* IDENTIFIERTEST_HPP */

