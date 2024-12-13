#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#include "StringOperations.h"

using namespace std;
#define ll long long int
#define endl "\n"

StringOperations *stringOp = new StringOperations();

int main() {

    ifstream in("/home/amethystmac/Desktop/Ayy Coding/CPP/input.txt");
    string line;

    int ans = 0;
    while(getline (in, line)) {

        vector<int> vec_line = stringOp->split(line, " ");

        int n = vec_line.size();

        bool isSafe = false;
        for(int j = 0; j < n; j++) {

            vector<int> temp_vec(vec_line);
            temp_vec.erase(temp_vec.begin() + j);

            int m = temp_vec.size();
            int inc = 0, dec = 0, same = 0;
            for(int i = 0; i < m - 1; i++) {
                if(abs(temp_vec[i] - temp_vec[i + 1]) > 3) {
                    break;
                }

                if(temp_vec[i] < temp_vec[i + 1]) inc++;
                else if(temp_vec[i] > temp_vec[i + 1]) dec++;
                else same++;
            }
        
            if(inc == m - 1 || dec == m - 1) isSafe = true;

            if(isSafe) break;
        }

        if(isSafe) ans++;
    }
    
    cout << ans;
}