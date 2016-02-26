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

#include "TokenTypes.hpp"

using namespace lexer;
using namespace scanner;
using namespace token;


const std::string IDENTIFIER_START_CHARS = "abcdefghijklmnopqrstuvwxyzQBCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string IDENTIFIER_CHARS = IDENTIFIER_START_CHARS + "0123456789";

const std::string NUMBER_CHARS = "0123456789";

const std::string KEYWORD_START_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string KEYWORD_CHARS = KEYWORD_START_CHARS + "0123456789";


std::map<std::string, std::string> keywordToTTypeMap;
void populateKeywordToTTypeMap();


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
    
    populateKeywordToTTypeMap();
    
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
                sc.startCountingMovements();
                
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                std::string tokenString(1, c);
                
                while (IDENTIFIER_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                // If identifier is not in keyword-TokenType map
                // (hence, if identifier is not a keyword)
                if (keywordToTTypeMap.find(tokenString) == keywordToTTypeMap.end()) {
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
                
                return Token(lineNumber, columnNumber, tokenString, TType::Values::Number);
            }
            
            return Token();
        }
    );
    
    // Keywords
    lexr.addTest(
        [] (Scanner& sc) {
            char c = sc.getCurrentChar();
            if (KEYWORD_START_CHARS.find(c) != std::string::npos) {
                sc.startCountingMovements();
                
                std::string tokenString(1, c);
                int lineNumber = sc.getLineNumber();
                int columnNumber = sc.getColumnNumber();
                
                while (KEYWORD_CHARS.find(sc.fetchNextChar()) != std::string::npos) {
                    tokenString += sc.moveToNextChar();
                }
                
                if (keywordToTTypeMap.find(tokenString) != keywordToTTypeMap.end()) {
                    return Token(lineNumber, columnNumber, tokenString, keywordToTTypeMap[tokenString]);
                }
                else {
                    sc.reset();
                }
            }
            
            return Token();
        }
    );
    
    // Space
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


void populateKeywordToTTypeMap()
{
    keywordToTTypeMap["write"] = TType::Keywords::Write;
    keywordToTTypeMap["let"] = TType::Keywords::Let;
}


#endif /* KCLLEXER_HPP */

