#ifndef _sum_h_
#define _sum_h_

#include "expression.h"

class Sum : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:
    Sum(Expression *left, Expression *right);
    float evaluate() override;
    std::string toString() override;
    ~Sum();
};

#endif