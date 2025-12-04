#include "InputOutputStream.h"

void InputOutputStream::readFile(std::string path) {

    std::ifstream in(path);
    std::string line;

    int ans = 0;
    while(getline (in, line)) {
        lines.push(line);
    }

}

std::string InputOutputStream::getCurrentDirectory() {
    std::filesystem::path currentDir = std::filesystem::current_path();
    return currentDir.string();
}

std::string InputOutputStream::getLine() {
    
    if (lines.empty()) return "";

    std::string line = lines.front();
    lines.pop();

    return line;
}
