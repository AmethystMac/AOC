#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
    vector<int> dos = stringOp->findSubstringIndices(line, "do()");
    vector<int> donts = stringOp->findSubstringIndices(line, "don't()");

    map<int, bool> conditionals;

    conditionals[0] = true;
    for(int i : dos) conditionals[i] = true;
    for(int i : donts) conditionals[i] = false;

    map<int, bool>::iterator conditional_it = conditionals.begin();
    vector<pair<string, string>> operand_pairs;
    for(int i : indices) {

        while(next(conditional_it) != conditionals.end() && (next(conditional_it))->first < i) {
            conditional_it++;
            continue;
        }
        if(!conditional_it->second) continue;

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
    string full = "", line;

    int ans = 0;
    while(getline (in, line)) {
        full += line;
    }
    int n = line.size();
    vector<int> mulOp = mulOperations(full);
    
    for(int i : mulOp) ans += i;
    
    cout << ans;
}
