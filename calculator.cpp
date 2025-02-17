#include "calculator.h"
#include <iostream>

class Integer : public Expression {
    private:
    int value = 0;

    public:

    Integer(int value): value(value) {}

    float evaluate()  {
        return value;
    }

    std::string toString() {
        return std::to_string(value);
    }
};

class Sum : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:

    Sum(Expression *left, Expression *right): left(left), right(right) {};

    float evaluate()  {
        return left->evaluate() + right->evaluate();
    }

    std::string toString() {
        return "(" + left->toString() + " + " + right->toString() + ")";
    }
};

class Subtraction : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:

    Subtraction(Expression *left, Expression *right): left(left), right(right) {};

    float evaluate()  {
        return left->evaluate() - right->evaluate();
    }

    std::string toString() {
        return "(" + left->toString() + " - " + right->toString() + ")";
    }
};

class Multiplication : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:

    Multiplication(Expression *left, Expression *right): left(left), right(right) {};

    float evaluate()  {
        return left->evaluate() * right->evaluate();
    }

    std::string toString() {
        return "(" + left->toString() + " * " + right->toString() + ")";
    }
};

class Division : public Expression {
    private:
    Expression *left;
    Expression *right;

    public:

    Division(Expression *left, Expression *right): left(left), right(right) {};

    float evaluate()  {
        return left->evaluate() / right->evaluate();
    }

    std::string toString() {
        return "(" + left->toString() + " / " + right->toString() + ")";
    }
};

int main() {
    Expression *expression = new Division(new Integer(20), new Multiplication(new Integer(5), new Integer(2)));
    std::cout << "Evaluating expression: " << expression->toString() << std::endl;
    std::cout << "Value: " << expression->evaluate() << std::endl;
}
