/*
 * StringConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/StringConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a string in the source code
 * 
 *        Usage: Will by used in statement constructs, which will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef STRINGCONSTRUCT_HPP
#define STRINGCONSTRUCT_HPP

#include <Construct.hpp>

using namespace ast;

SP<Construct> string()
{
    SP<Construct> string_constr(new Construct("String", TType::Values::String, NType::Values::String, 0, 0));
    
    SP<ConstructTreeFormNode> string_treeForm(new ConstructTreeFormNode("String"));
    
    string_constr->treeForm = string_treeForm;
    
    return string_constr;
}


#endif /* STRINGCONSTRUCT_HPP */

