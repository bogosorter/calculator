#include "elements/elements.h"

#include <iostream>

int main() {
    Expression *expression = new Division(new Integer(20), new Multiplication(new Integer(5), new Integer(3)));
    std::cout << "Evaluating expression: " << expression->toString() << std::endl;
    std::cout << "Value: " << expression->evaluate() << std::endl;
}
