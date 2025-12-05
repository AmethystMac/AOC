#include <iostream>

#include "InputOutputStream.h"

using namespace std;
#define ll long long int
#define endl "\n"

InputOutputStream ioStream;

int main() {

    ioStream.readFile(ioStream.getCurrentDirectory() + "/../input.txt");

    int ans = 0, currVal = 50;
    string line;
    while ((line = ioStream.getLine()) != "") {
        int rotations = stoi(line.substr(1));
        if (line[0] == 'L') {
            int currForLeft = (currVal == 0) ? 100 : currVal;
            int hitsDuring = (rotations + (100 - currForLeft)) / 100;
            ans += hitsDuring;

            currVal = (currVal - rotations) % 100;
            if (currVal < 0) currVal += 100;
        } else {
            int hitsDuring = (currVal + rotations) / 100;
            ans += hitsDuring;

            currVal = (currVal + rotations) % 100;
        }
    }
    
    cout << ans;
}
