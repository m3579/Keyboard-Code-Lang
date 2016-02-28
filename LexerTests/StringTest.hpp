/*
 * StringTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/StringTests.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds test to the lexer for a string
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef STRINGTEST_HPP
#define STRINGTEST_HPP

#include <Lexer.hpp>

#include "utilities.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;


const char STRING_START_END_CHAR = '"';

void addStringTest(Lexer& lexr)
{
    lexr.addTest(
        [] (Scanner& sc) {
            std::cout << "Running String test...\n";
            
            char c = sc.getCurrentChar();
            if (c == STRING_START_END_CHAR) {
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while ((sc.fetchNextChar() != '\0')
                       && (sc.fetchNextChar() != STRING_START_END_CHAR)) {
                    tokenString += sc.moveToNextChar();
                }
                
                // TODO: decide if sc.moveToNextChar() here before the error is thrown
                // is necessary
                if (sc.fetchNextChar() == '\0') {
                    utilities::logError("This string was not closed with a double quote", true);
                }
                
                // We need to move to the last char of the string (which is the closing quote)
                // We also add that closing quote to the token's text
                tokenString += sc.moveToNextChar();
                
                return Token(lineNumber, columnNumber, tokenString, TType::Values::String);
            }
            
            return Token();
        }
    );
}
        

#endif /* STRINGTEST_HPP */

