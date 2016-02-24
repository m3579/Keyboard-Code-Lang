/*
 * NodeTypes.hpp
 *
 * /KeyboardCodeLang/NodeTypes.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 23, 2016
 *
 *      Purpose: Defines the node types used in KeyboardCodeLang's compiler. The
 *              NodeTypes are a way to identify nodes in the AST  (Abstract Syntax Tree)
 *              of the source code, such as NType::Number and NType::OperandAdd.
 *
 *        Usage: Will be used in the parser and in the AST
 *
 *        Notes: 
 *
 */

#ifndef NODETYPES_HPP
#define NODETYPES_HPP

#include <NodeType.h>

namespace NType
{
    namespace Testing
    {
        createNodeType(LetterA);
    }
    
    createNodeType(End);
}

#endif /* NODETYPES_HPP */

