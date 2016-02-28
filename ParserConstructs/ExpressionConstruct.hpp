/*
 * ExpressionConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/ExpressionConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing an expression in the source code (an operator and its operands, which
 *              may also be operators and operands themselves)
 *
 *        Usage: Will be used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef EXPRESSIONCONSTRUCT_HPP
#define EXPRESSIONCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;


SP<Construct> expression()
{
    std::vector<SP<Construct>> expression_possible_constructs {
        
    };
}


#endif /* EXPRESSIONCONSTRUCT_HPP */

