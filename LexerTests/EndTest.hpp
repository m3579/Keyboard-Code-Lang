/*
 * EndTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/EndTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Adds a test to the lexer for the end of the source code (the "\0" character)
 *
 *        Usage: Will be used by the lexer to get tests
 *
 *        Notes: 
 *
 */

#ifndef ENDTEST_HPP
#define ENDTEST_HPP

#include <Lexer.hpp>

using namespace lexer;
using namespace scanner;
using namespace token;

void addEndTest(Lexer& lexr)
{
    lexr.addTest(
        [] (Scanner& sc) {
            if (sc.getCurrentChar() == '\0') {
                sc.finished = true;
                return Token(sc.getLineNumber(), sc.getColumnNumber(), "\0", TType::End);
            }
            
            return Token();
        }
    );
}


#endif /* ENDTEST_HPP */
