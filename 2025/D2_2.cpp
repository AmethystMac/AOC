#include <iostream>

#include "StringOperations.h"
#include "InputOutputStream.h"

using namespace std;
#define ll long long int
#define endl "\n"

StringOperations stringOp;
InputOutputStream ioStream;

bool isInvalidId(string &id) {

    int len = id.length();

    for (int patternLen = 1; patternLen <= len / 2; patternLen++) {
        if (len % patternLen != 0) continue;

        string pattern = id.substr(0, patternLen);
        string rebuiltPattern = "";

        for (int i = 0; i < len / patternLen; i++) {
            rebuiltPattern += pattern;
        }

        if (rebuiltPattern == id) return true;
    }
    
    return false;
}

ll findInvalidIds(string &line) {

    vector<string> idRanges = stringOp.splitByDelimiter(line, ",");

    ll ans = 0;
    for (string idRange : idRanges) {
        vector<string> ids = stringOp.splitByDelimiter(idRange, "-");
        ll intStartId = stoll(ids[0]), intEndId = stoll(ids[1]);

        for (ll intId = intStartId; intId <= intEndId; intId++) {
            string id = to_string(intId);

            if (isInvalidId(id)) {
                ans += intId;
            }
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
