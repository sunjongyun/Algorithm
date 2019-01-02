//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);

    vector<int> v;
    string input = "";
    while (ss >> input) {
        v.push_back(stoi(input));
    }

    sort(v.begin(), v.end());
    return to_string(v[0]) + " " + to_string(v[v.size() - 1]);
}

int main() {
    cout << solution("-1 -1") << '\n';
    return 0;
}