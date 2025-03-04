#ifndef _integer_h_
#define _integer_h_

#include "expression.h"

class Integer : public Expression {
    private:
    int value;

    public:
    Integer(int value);
    float evaluate() override;
    std::string toString() override;
};

#endif
