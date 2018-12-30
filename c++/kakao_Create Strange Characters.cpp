//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            answer += (index & 1 ? tolower(s[i]) : toupper(s[i]));
            index++;
        } else {
            answer += ' ';
            index = 0;
        }
    }

    return answer;
}

int main() {
    cout << solution("try hello world") << '\n';

    return 0;
}