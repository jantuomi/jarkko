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
    std::string input = readFile(filename);
    std::cout << input;

    Parser parser(input);
    parser.printTokens();

    Runtime runtime;
    runtime.run(parser.getTokens());

    return 0;
}
