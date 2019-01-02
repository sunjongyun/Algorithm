//
// Created by SUN on 2019-01-03.
//

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;

    stack<char> st;

    int index = 0;
    while (index != s.size()) {
        if (s[index] == '(') {
            st.push('(');
        } else {
            if (st.size() > 0) {
                st.pop();
            } else {
                answer = false;
                break;
            }
        }
        index++;
    }

    return answer && st.size() == 0;
}

int main() {
    cout << solution("(()(") << '\n';

    return 0;
}