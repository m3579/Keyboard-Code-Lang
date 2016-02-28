/*
 * LetStatement.hpp
 *
 * /KeywordCodeLang/ParserStatement/LetStatement.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a "let" statement - a variable declaration
 *
 *        Usage: Will be used in the parser
 *
 *        Notes: 
 *
 */

#ifndef LETSTATEMENT_HPP
#define LETSTATEMENT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> letStatement()
{
    std::vector<SP<Construct>> let_stmt_components {
        keyword_let(), identifier(), whitespace()->getOptionalForm(), 
    };
}

#endif /* LETSTATEMENT_HPP */

