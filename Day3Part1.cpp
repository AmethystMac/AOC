#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#include "IntOperations.h"
#include "StringOperations.h"

using namespace std;
#define ll long long int
#define endl "\n"

IntOperations *intOp = new IntOperations();
StringOperations *stringOp = new StringOperations();

vector<pair<string, string>> getMulOperands(string line) {
    
    int n = line.size();
    vector<int> indices = stringOp->findSubstringIndices(line, "mul");

    vector<pair<string, string>> operand_pairs;
    for(int i : indices) {

        string first_operand = "", second_operand = "";
        if(line[i + 3] == '(') {
            
            i += 4;
            
            int comma = line.find(',', i);
            if(comma != string::npos) {

                first_operand = line.substr(i, comma - i);
                comma++;
                int closing_bracket = line.find(')', comma);
                second_operand = line.substr(comma, closing_bracket == string::npos ? 0 : closing_bracket - comma);
            }
        }

        cout << first_operand << " " << second_operand << "\n";
        if(first_operand != "" && second_operand != "") {
            operand_pairs.push_back(make_pair(first_operand, second_operand));
        }
    }

    return operand_pairs;
}

vector<int> mulOperations(string line) {

    vector<pair<string, string>> operand_pairs = getMulOperands(line);

    vector<int> mul;
    for(pair<string, string> operands : operand_pairs) {
        if(intOp->isInteger(operands.first) && intOp->isInteger(operands.second)) {
            mul.push_back(stoi(operands.first) * stoi(operands.second));
        }
    }

    return mul;
}

int main() {

    ifstream in("/home/amethystmac/Desktop/Ayy Coding/CPP/input.txt");
    string line;

    int ans = 0;
    while(getline (in, line)) {

        int n = line.size();
        vector<int> mulOp = mulOperations(line);
        
        for(int i : mulOp) ans += i;
    }
    
    cout << ans;
}