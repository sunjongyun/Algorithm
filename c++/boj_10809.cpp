//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; ++i) {
        auto it = find(s.begin(), s.end(), i);
        if (it == s.end()) {
            cout << -1 << ' ';
        } else {
            cout << (it - s.begin()) << ' ';
        }
    }


    return 0;
}