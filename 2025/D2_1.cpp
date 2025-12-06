#include <iostream>

#include "StringOperations.h"
#include "InputOutputStream.h"

using namespace std;
#define ll long long int
#define endl "\n"

StringOperations stringOp;
InputOutputStream ioStream;

ll findInvalidIds(string line) {
    vector<string> idRanges = stringOp.splitByDelimiter(line, ",");

    ll ans = 0;
    for (string idRange : idRanges) {
        vector<string> ids = stringOp.splitByDelimiter(idRange, "-");
        string startId = ids[0], endId = ids[1];
        ll intStartId = stoll(startId), intEndId = stoll(endId);

        string id = startId;
        ll intId = intStartId;
        while (intId <= intEndId) {
            if (id.size() % 2 == 0) {
                auto halfPair = stringOp.splitMid(id);
                if (halfPair.first == halfPair.second) {
                    ans += intId;
                }
            }

            intId++;
            id = to_string(intId);
        }
    }

    return ans;
}

int main() {

    ioStream.readFile(ioStream.getCurrentDirectory() + "/../input.txt");

    ll ans;
    string line;
    while ((line = ioStream.getLine()) != "") {
        ans = findInvalidIds(line);
    }
    
    cout << ans;
}
