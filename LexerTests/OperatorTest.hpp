/*
 * OperatorTest.hpp
 *
 * /KeyboardCodeLang/LexerTests/OperatorTest.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2015
 *
 *      Purpose: Adds a test to the lexer for operators
 *        // TODO: modify this "Usage" header to be more coherent
 *        Usage: Will be used in the lexer to get tests
 *        
 *        Notes: 
 *
 */

#ifndef OPERATORTEST_HPP
#define OPERATORTEST_HPP

#include <Lexer.hpp>

using namespace lexer;
using namespace scanner;
using namespace token;

std::map<std::string, std::string> operatorToTTypeMap;

void addOperatorTest(Lexer& lexr)
{
    operatorToTTypeMap["+"] = TType::Operators::Plus;
    operatorToTTypeMap["-"] = TType::Operators::Minus;
    operatorToTTypeMap["*"] = TType::Operators::Asterisk;
    operatorToTTypeMap["/"] = TType::Operators::ForwardSlash;
    operatorToTTypeMap["="] = TType::Operators::Equals;
    
    lexr.addTest(
        [] (Scanner& sc) {
            std::cout << "Running Operator test...\n";
            
            std::string s(1, sc.getCurrentChar());
            if (operatorToTTypeMap.find(s) != operatorToTTypeMap.end()) {
                return Token(sc.getLineNumber(), sc.getColumnNumber(), s, operatorToTTypeMap[s]);
            }
            
            return Token();
        }
    );
}


#endif /* OPERATORTEST_HPP */

