/*
 * utilities.hpp
 *
 * /KeyboardCodeLang/utilities.hpp
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

#ifndef UTILITIES_HPP
#define UTILITIES_HPP


namespace utilities
{
    void logError(std::string message, bool fatal);
}


#endif /* UTILITIES_HPP */

