/*
 * utilities.cpp
 *
 * /KeyboardCodeLang/utilities.cpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Feb 25, 2016
 *
 *      Purpose: Contains utilities and declarations used throughout the compiler,
 *              such as functions for logging errors.
 *
 *        Usage: Will be invoked by various components of the compiler
 *
 *        Notes: 
 *
 */

#include <iostream>
#include <stdexcept>

#include "utilities.hpp"

namespace utilities
{
    void logError(std::string message, bool fatal)
    {
        std::cout << "Error: " << message;
        
        if (fatal) {
            throw std::runtime_error("Fatal error: " + message);
        }
    }
}