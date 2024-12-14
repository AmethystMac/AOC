#include "IntOperations.h"

bool IntOperations::isInteger(std::string source) {
    return !source.empty() && source.find_first_not_of("0123456789") == std::string::npos;
}