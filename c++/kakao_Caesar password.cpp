//
// Created by SUN on 2018-12-31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        char now = s[i];
        if (now == ' ') {
            answer += ' ';
        } else {
            for (int j = 0; j < n; j++) {
                now++;
                if (now == ('z' + 1)) {
                    now = 'a';
                }
                if (now == 'Z' + 1) {
                    now = 'A';
                }
            }
            answer += now;
        }
    }

    return answer;
}

int main() {

    cout << solution("Z B z", 4) << '\n';

    return 0;
}