#include "integer.h"

Integer::Integer(int value) : value(value) {}

float Integer::evaluate() {
    return value;
}

std::string Integer::toString() {
    return std::to_string(value);
}