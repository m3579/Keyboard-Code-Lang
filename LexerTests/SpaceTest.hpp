/*
 * SpaceTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/SpaceTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds test in the lexer for spaces
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef SPACETEST_HPP
#define SPACETEST_HPP

#include <Lexer.hpp>

using namespace lexer;
using namespace scanner;
using namespace token;

void addSpaceTest(Lexer& lexr)
{
    lexr.addTest(
        [] (Scanner& sc) {
            char c = sc.getCurrentChar();
            if (c == ' ') {
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while (sc.fetchNextChar() == ' ') {
                    tokenString += sc.moveToNextChar();
                }
                
                return Token(lineNumber, columnNumber, tokenString, TType::Whitespace::Space);
            }
            
            return Token();
        }
    );
}


#endif /* SPACETEST_HPP */

