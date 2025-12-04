#include <iostream>

#include "IntOperations.h"
#include "StringOperations.h"
#include "InputOutputStream.h"

using namespace std;
#define ll long long int
#define endl "\n"

IntOperations intOp;
StringOperations stringOp;
InputOutputStream ioStream;

int main() {

    ioStream.readFile(ioStream.getCurrentDirectory() + "/input.txt");

    int ans = 0, currVal = 50;
    string line;
    while ((line = ioStream.getLine()) != "") {
        int rotations = stoi(line.substr(1));
        if (line[0] == 'L') {
            currVal = (currVal - rotations) % 100;
        } else {
            currVal = (currVal + rotations) % 100;
        }
        if (!currVal) ans++;
    }
    
    cout << ans;
}
