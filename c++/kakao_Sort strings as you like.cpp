//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {

    sort(strings.begin(), strings.end(), [n](const string &u, const string &v) {
        if (u[n] < v[n]) {
            return true;
        } else if (u[n] == v[n]) {
            return u < v;
        } else {
            return false;
        }
    });

    return strings;
}

int main() {
//    auto ans = solution(vector<string>{"sun", "bed", "car"}, 1);
    auto ans = solution(vector<string>{"abce", "abcd", "cdx"}, 2);

    for (string x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}