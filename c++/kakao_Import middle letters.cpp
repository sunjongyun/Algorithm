//
// Created by SUN on 2018-12-30.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int half = s.size() / 2;

    if (s.size() % 2 == 1) {
        answer += s[half];
    } else {
        answer += s[half - 1];
        answer += s[half];
    }

    return answer;
}

int main() {
    auto ans = solution(string("qwerab"));

    cout << ans << '\n';
    return 0;
}