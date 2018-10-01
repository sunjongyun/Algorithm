//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;

    cin >> s;

    for (char c = 'a'; c <= 'z'; c++) {
        int ans = count(s.begin(), s.end(), c);
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}