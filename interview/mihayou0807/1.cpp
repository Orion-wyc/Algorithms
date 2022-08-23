#include <bits/stdc++.h>
using namespace std;

int solve(string &input) {
    stringstream ss(input);
    string s;
    int cnt = 0;
    while (getline(ss, s, '<')) {
        cnt ++;
    }
    return cnt / 2;
}

int main() {
    string input;
    while (cin >> input) {
        cout << solve(input) << endl;
    }
    return 0;
}