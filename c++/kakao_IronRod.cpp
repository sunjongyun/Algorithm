//
// Created by SUN on 2018-12-08.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;

    for (int i = 0; i < arrangement.length() - 1; i++) {
        // You should divide the case of laser and the case of non-laser.
        string raser = arrangement.substr(i, 2);

        if (raser == "()") {
            // If it is a laser, it fetches size () of stack.
            answer += s.size();
            i++;
        } else {

            // If it is a Non-laser
            if (arrangement[i] == '(') {
                s.push(1);
            } else if (arrangement[i] == ')') {
                answer += s.top();
                s.pop();
            }
        }
    }

    // You should think about the case where the laser can come out at the end or the iron rod.
    int last = arrangement.length() - 2;
    if (arrangement.substr(last, last + 2) != "()") {
        answer += s.top();
        s.pop();
    }

    return answer;
}

int main() {
    string s = "()(((()())(())()))(())";

    int ans = solution(s);

    cout << ans << '\n';

    return 0;
}