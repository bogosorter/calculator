#ifndef _calculator_h_
#define _calculator_h_

#include <string>

class Expression {
    public:
    virtual float evaluate() = 0;
    virtual std::string toString() = 0;
};

#endif
