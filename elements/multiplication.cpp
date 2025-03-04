#include "multiplication.h"

Multiplication::Multiplication(Expression *left, Expression *right) 
    : left(left), right(right) {}

float Multiplication::evaluate() {
    return left->evaluate() * right->evaluate();
}

std::string Multiplication::toString() {
    return "(" + left->toString() + " * " + right->toString() + ")";
}