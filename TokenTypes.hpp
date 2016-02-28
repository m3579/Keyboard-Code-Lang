/*
 * TokenTypes.hpp
 *
 * /KeyboardCodeLang/TokenTypes.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 23, 2016
 *
 *      Purpose: Defines the TokenTypes used in the KeyboardCodeLang compiler.
 *              TokenTypes are a way of classifying the tokens obtained from the
 *              source code by the lexer; i.e. TType::Number, TType::PlusSign.
 *
 *        Usage: The lexer will use the TokenTypes defined in this namespace.
 *
 *        Notes: 
 *
 */

#ifndef TOKENTYPES_HPP
#define TOKENTYPES_HPP

#include <TokenType.h>

namespace TType
{
    namespace Testing
    {
        createTokenType(LetterA);
    }
    
    namespace Keywords
    {
        createTokenType(Write);
        createTokenType(Let);
    }
    
    createTokenType(Identifier);
    
    namespace Values
    {
        createTokenType(Number);
        createTokenType(String);
    }
    
    namespace Whitespace
    {
        createTokenType(Space);
    }
    
    createTokenType(End);
}

#endif /* TOKENTYPES_HPP */

