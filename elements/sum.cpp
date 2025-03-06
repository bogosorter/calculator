#include "sum.h"

Sum::Sum(Expression *left, Expression *right) 
    : left(left), right(right) {}

float Sum::evaluate() {
    return left->evaluate() + right->evaluate();
}

std::string Sum::toString() {
    return "(" + left->toString() + " + " + right->toString() + ")";
}

Sum::~Sum() {
    delete left;
    delete right;
}
