#ifndef _division_h_
#define _division_h_

#include "expression.h"

class Division : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:
    Division(Expression *left, Expression *right);

    float evaluate() override;
    std::string toString() override;
};

#endif
