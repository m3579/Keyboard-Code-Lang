/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: keyboardcode.cpp
 * Author: Mihir Kasmalkar
 *
 * Created on February 23, 2016, 9:44 PM
 */

#include <iostream>
#include <exception>
#include <fstream>
#include <string>

#include <utilities.h>

#include "KCLLexer.hpp"
#include "KCLParser.hpp"

using namespace pointer;

/**
 * The entry point into the compiler.
 * 
 * Usage:
 *     keyboardcode filename_to_compile
 */
int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "You must specify a filename\n";
        return 1;
    }
    
    try {
        std::string filename(argv[1]);
        std::ifstream file(filename);
        
        std::string text;
        
        std::string line;
        while (std::getline(file, line)) {
            text += line + "\n";
        }
        
        file.close();
        
        Parser parser(getParser(getLexer(text)));
        SP<SyntaxTree> tree(parser.createSyntaxTree());
        tree->print("");    
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << "\n";
    }
}

