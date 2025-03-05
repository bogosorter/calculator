#include "elements/elements.h"
#include "parser/parser.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "> ";
    std::string line;
    getline(std::cin, line);

    std::vector<Token> tokens = Parser::tokenize(line);
    for (Token token : tokens) {
        std::cout << token.lexeme << " " << token.tokenType << " " << token.column << std::endl;
    }
}
