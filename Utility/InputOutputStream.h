#pragma once

#include <iostream>
#include <queue>
#include <fstream>
#include <filesystem>

class InputOutputStream {
private:
    std::queue<std::string> lines;

public:
    void readFile(std::string path);
    std::string getCurrentDirectory();
    std::string getLine();
};
