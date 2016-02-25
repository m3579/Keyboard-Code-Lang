/*
 * KCLLexer.hpp
 *
 * /KeyboardCodeLang/KCLLexer.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 23, 2016
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

#include <Lexer.hpp>

#include "TokenTypes.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;


const std::string IDENTIFIER_START_CHARS = "abcdefghijklmnopqrstuvwxyzQBCDEFGHIJKLMNOPQRSTUVWXYZ_";
const std::string IDENTIFIER_CHARS = IDENTIFIER_START_CHARS + "0123456789";

const std::string NUMBER_CHARS = "0123456789";

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
    
    // TESTING
    
    // This test is used in testing the lexer; it simply sees if the lexer is
    // at the lowercase letter a
//    lexr.addTest(
//        [] (Scanner& sc) {
//             if (sc.getCurrentChar() == 'a') {
//                std::cout << "Found letter a in lexer\n";
//                return Token(sc.getLineNumber(), sc.getColumnNumber(), "a", TType::Testing::LetterA);
//            }
//            return Token();
//        }
//    );
    
    // END TESTING
    
    // Identifier
    lexr.addTest(
        [] (Scanner& sc) {
            char c = sc.getCurrentChar();
            if (IDENTIFIER_START_CHARS.find(c) != std::string::npos) {
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while (IDENTIFIER_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                return Token(lineNumber, columnNumber, tokenString, TType::Identifier);
            }
            
            return Token();
        }
    );
    
    // Number
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
                
                return Token(lineNumber, columnNumber, tokenString, TType::Number);
            }
            
            return Token();
        }
    );
    
    // End
    lexr.addTest(
        [] (Scanner& sc) {
            if (sc.getCurrentChar() == '\0') {
                sc.finished = true;
                return Token(sc.getLineNumber(), sc.getColumnNumber(), "\0", TType::End);
            }
            
            return Token();
        }
    );
    
    return lexr;
}

#endif /* KCLLEXER_HPP */

