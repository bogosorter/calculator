#include "elements/elements.h"
#include "parser/parser.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "> ";
    std::string line;
    getline(std::cin, line);

    std::vector<Token> tokens = Parser::tokenize(line);
    for (auto token : tokens) std::cout << token.lexeme << " " << token.tokenType << std::endl;
    Expression *expression = Parser::parse(tokens);

    std::cout << expression->toString() << std::endl;

    std::cout << "< " << expression->evaluate() << std::endl;
}
