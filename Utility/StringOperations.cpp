#include "StringOperations.h"

StringOperations::StringOperations() {}

std::pair<std::string, std::string> StringOperations::splitMid(std::string source) {

    std::pair<std::string, std::string> halves;
    ll mid = source.size() / 2;
    halves.first = source.substr(0, mid);
    halves.second = source.substr(mid);

    return halves;
}

std::vector<std::string> StringOperations::splitByDelimiter(std::string source, std::string delimiter) {

    std::vector<std::string> items;
    size_t prev_delim_index = 0, next_delim_index = 0;
    while((next_delim_index = source.find(delimiter, prev_delim_index)) != std::string::npos) {
        std::string new_string = source.substr(prev_delim_index, next_delim_index - prev_delim_index);
        items.push_back(new_string);

        prev_delim_index = next_delim_index + delimiter.size();
    }
    std::string new_string = source.substr(prev_delim_index);
    items.push_back(new_string);

    return items;
}

std::vector<int> StringOperations::findSubstringIndices(std::string source, std::string substring) {

    std::vector<int> items;
    size_t search_index = 0;
    while((search_index = source.find(substring, search_index)) != std::string::npos) {

        items.push_back(search_index);
        search_index += substring.size();
    }

    return items;
}