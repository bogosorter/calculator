#ifndef _multiplication_h_
#define _multiplication_h_

#include "expression.h"

class Multiplication : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:
    Multiplication(Expression *left, Expression *right);

    float evaluate() override;
    std::string toString() override;
};

#endif
