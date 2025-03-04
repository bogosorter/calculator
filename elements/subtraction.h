#ifndef _subtraction_h_
#define _subtraction_h_

#include "expression.h"

class Subtraction : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:
    Subtraction(Expression *left, Expression *right);

    float evaluate() override;
    std::string toString() override;
};

#endif
