#include <StringOperations.h>

StringOperations::StringOperations() {}

std::vector<int> StringOperations::split(std::string source, std::string delimiter) {

    std::vector<int> items;
    size_t prev_delim_index = 0, next_delim_index = 0;
    while((next_delim_index = source.find(delimiter, prev_delim_index)) != std::string::npos) {

        std::string new_string = source.substr(prev_delim_index, next_delim_index);
        items.push_back(stoi(new_string));

        prev_delim_index = next_delim_index + delimiter.size();
    }
    std::string new_string = source.substr(prev_delim_index, source.size());
    items.push_back(stoi(new_string));

    return items;
}