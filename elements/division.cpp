#include "division.h"

Division::Division(Expression *left, Expression *right): left(left), right(right) {};

float Division::evaluate()  {
    return left->evaluate() / right->evaluate();
}

std::string Division::toString() {
    return "(" + left->toString() + " / " + right->toString() + ")";
}
