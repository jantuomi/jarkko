#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include "parser.h"
#include "runtime.h"

std::string readFile(std::string& filename) {
    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)),
                    (std::istreambuf_iterator<char>()));
    return str;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Please supply input file name as a parameter." << std::endl;
        return 1;
    }

    std::string filename = std::string(argv[1]);
    std::string code = readFile(filename);

    std::string valueString;
    std::string stdinLine;
    while (std::cin >> stdinLine) {
        valueString += stdinLine + " ";
    }

    Parser parser;
    std::vector<Token> tokens = parser.parseCode(code);
    std::vector<int> values = parser.parseValues(valueString);
    parser.printTokens(tokens);
    parser.printValues(values);

    Runtime runtime;
    runtime.initValues(values);
    runtime.run(tokens);

    return 0;
}
