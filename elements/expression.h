#ifndef _expression_h_
#define _expression_h_

#include <string>

class Expression {
    public:
    virtual float evaluate() = 0;
    virtual std::string toString() = 0;
    // TODO: clean on destructuring
};

#endif
