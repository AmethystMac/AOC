#pragma once
#include <iostream>
#include <vector>

class StringOperations {
public:
    StringOperations();
    std::vector<int> split(std::string source, std::string delimiter);
};