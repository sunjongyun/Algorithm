//
// Created by SUN on 2018-12-07.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char open[] = {'(', '{', '['};
char close[] = {')', '}', ']'};
int gap[] = {'(' - ')', '{' - '}', '[' - ']'};

bool solution(string input) {
    bool ret = true;
    stack<char> s;


    for (int i = 0; i < input.size(); i++) {
        char now = input[i];

        for (int k = 0; k < 3; k++) {
            if (open[k] == now) {
                s.push(now);
                break;
            }
            if (close[k] == now) {
                if (!s.empty()) {
                    char prev = s.top();
                    s.pop();

                    if (prev - now == gap[k]) {
                        ret = true;
                    } else {
                        ret = false;
                        return ret;
                    }
                    break;
                } else {
                    ret = false;
                    return ret;
                }
            }
        }
    }

    // If there are remaining elements in the stack
    if (s.size() != 0) {
        ret = false;
    } else {
        ret = true;
    }

    return ret;
}

int main() {

    int testcase;
    cin >> testcase;

    while (testcase--) {

        string input;
        cin >> input;

        bool ans = solution(input);

        if (ans) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }


    return 0;
}