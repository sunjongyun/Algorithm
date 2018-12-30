//
// Created by SUN on 2018-12-31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {

    sort(s.begin(), s.end(), [](const char &u, const char &v) {
        int a = 'a' <= u && u <= 'z' ? 100 + u : u;
        int b = 'a' <= v && v <= 'z' ? 100 + v : v;

        return a > b;
    });

    return s;
}

int main() {

    string ans = solution(string("Zbcdefg"));

    cout << ans << '\n';

    return 0;
}