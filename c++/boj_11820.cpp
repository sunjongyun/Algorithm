//
// Created by mac on 2018. 9. 30..
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        int small = 0;
        int big = 0;
        int num = 0;
        int space = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if ('0' <= c && c <= '9') {
                num++;
            } else if ('a' <= c && c <= 'z') {
                small++;
            } else if ('A' <= c && c <= 'Z') {
                big++;
            } else if (' ' == c) {
                space++;
            }
        }

        cout << small << ' ' << big << ' ' << num << ' ' << space << '\n';
    }


    return 0;
}