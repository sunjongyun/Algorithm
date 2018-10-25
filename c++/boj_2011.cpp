//
// Created by SUN on 2018-10-19.
//

#include <iostream>
#include <string>

using namespace std;

const int c1 = 0; // If the current text is a single digit
const int c2 = 1; // If the current text is a double digit
const int mod = 1000000;

int main() {
    string s;
    cin >> s;

    int size = s.length();
    long long dp[size + 1][2];

    //dp array initialize
    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][c1] = 1;
    dp[0][c2] = 0;
    if (s[0] == '0') {
        cout << 0 << '\n';
    } else {
        dp[1][c1] = 1;
        dp[1][c2] = 0;

        for (int i = 2; i <= size; i++) {
            string tmp;
            if (s[i-1] != '0') {
                dp[i][c1] = (dp[i - 1][c1] + dp[i - 1][c2]) % mod;
            }
            tmp = s.substr(i - 2, 2);
            int num = stoi(tmp);
            if (0 <= num && num <= 26) {
                dp[i][c2] = (dp[i - 2][c1] + dp[i - 2][c2]) % mod;
            }
        }

        cout << (dp[size][c1] + dp[size][c2]) % mod << '\n';
    }


    return 0;
}