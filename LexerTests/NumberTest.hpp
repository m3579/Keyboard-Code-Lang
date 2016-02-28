/*
 * NumberTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/NumberTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds a test in the lexer for numbers
 *              // TODO: define number (and any other terms in lexer tests)
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef NUMBERTEST_HPP
#define NUMBERTEST_HPP

#include <Lexer.hpp>

using namespace lexer;
using namespace scanner;
using namespace token;

const std::string NUMBER_CHARS = "0123456789";

void addNumberTest(Lexer& lexr)
{
    // TODO: add support for decimal point and negative sign
    lexr.addTest(
        [] (Scanner& sc) {
            char c = sc.getCurrentChar();
            if (NUMBER_CHARS.find(c) != std::string::npos) {
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while (NUMBER_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                return Token(lineNumber, columnNumber, tokenString, TType::Values::Number);
            }
            
            return Token();
        }
    );
}

#endif /* NUMBERTEST_HPP */

