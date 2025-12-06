#pragma once

#include <iostream>
#include <vector>

#define ll long long int

class StringOperations {
public:
    StringOperations();
    std::pair<std::string, std::string> splitMid(std::string source);
    std::vector<std::string> splitByDelimiter(std::string source, std::string delimiter);
    std::vector<int> findSubstringIndices(std::string source, std::string substring);
};