#include "subtraction.h"

Subtraction::Subtraction(Expression *left, Expression *right) 
    : left(left), right(right) {}

float Subtraction::evaluate() {
    return left->evaluate() - right->evaluate();
}

std::string Subtraction::toString() {
    return "(" + left->toString() + " - " + right->toString() + ")";
}

Subtraction::~Subtraction() {
    delete left;
    delete right;
}