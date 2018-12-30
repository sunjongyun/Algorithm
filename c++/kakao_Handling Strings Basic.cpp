//
// Created by SUN on 2018-12-31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    bool isAllNumbers = true;
    for (int i = 0; i < s.size(); i++) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            isAllNumbers = false;
            break;
        }
    }

    return isAllNumbers && (4 == s.size() || s.size() == 6);
}

int main() {

    cout << solution("1234") << '\n';


    return 0;
}