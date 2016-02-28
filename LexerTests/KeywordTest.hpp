/*
 * KeywordTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/KeywordTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds a test to the lexer for keywords
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef KEYWORDTEST_HPP
#define KEYWORDTEST_HPP

#include <Lexer.hpp>

#include "TokenTypes.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;


const std::string KEYWORD_START_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string KEYWORD_CHARS = KEYWORD_START_CHARS + "0123456789";

void addKeywordTest(Lexer& lexr)
{
    lexr.addTest(
        [] (Scanner& sc) {
            std::cout << "Running Keyword test...\n";
            
            char c = sc.getCurrentChar();
            if (KEYWORD_START_CHARS.find(c) != std::string::npos) {
                sc.startCountingMovements();
                
                std::string tokenString(1, c);
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                
                while (KEYWORD_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                if (textToTTypeMap.find(tokenString) != textToTTypeMap.end()) {
                    return Token(lineNumber, columnNumber, tokenString, textToTTypeMap[tokenString]);
                }
                else {
                    sc.reset();
                }
            }
            
            return Token();
        }
    );
}


#endif /* KEYWORDTEST_HPP */

