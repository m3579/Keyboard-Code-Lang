/*
 * ValueConstruct.hpp
 *
 * /KeyboardCodeLang/ParserConstructs/ValueConstruct.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 27, 2016
 *
 *      Purpose: Creates a construct representing a value in the source code being compiled
 *
 *        Usage: Will be used by the parser
 *
 *        Notes: 
 *
 */

#ifndef VALUECONSTRUCT_HPP
#define VALUECONSTRUCT_HPP

#include <Construct.hpp>

#include "TokenTypes.hpp"
#include "NodeTypes.hpp"

using namespace ast;

SP<Construct> getValueConstruct()
{
    std::vector<TokenType> value_ttypes {
        TType::Values::Number, TType::Values::String, TType::Values::Identifier
    };
    std::vector<NodeType> value_ntypes {
        NType::Values::Number, TType::Values::String, TType::Values::Identifier
    };
    
    SP<Construct> value_constr(new Construct("Value", value_ttypes, value_ntypes, 0, 0));
    
    SP<ConstructTreeFormNode> value_treeForm(new ConstructTreeFormNode("Value"));
    value_constr->treeForm = value_treeForm;
    
    return value_constr;
}

#endif /* VALUECONSTRUCT_HPP */

