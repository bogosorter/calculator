#include "elements/elements.h"
#include "parser/parser.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "> ";
    std::string line;
    getline(std::cin, line);

    std::vector<Token> tokens = Parser::tokenize(line);
    Expression *expression = Parser::parse(tokens);
    std::cout << expression->evaluate() << std::endl;

    delete expression;
}
