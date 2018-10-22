//
// Created by mac on 2018. 10. 22..
//

#include <iostream>

using namespace std;

long long d[101][10];
const long long mod = 1000000000;

long long go(int n, int h) { // n은 길이, h는 층수
    if (n == 1) {
        return d[1][h];
    }

    if (d[n][h] > 0) return d[n][h];

    if ((h - 1) >= 0) { // 높이가 0이상일 경우
        d[n][h] += (go(n - 1, h - 1) % mod);
    }
    if ((h + 1) < 10) { // 높이가 10 미만일 경우
        d[n][h] += (go(n - 1, h + 1) % mod);
    }

    return d[n][h];
}

int main() {
    // init
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 10; j++) {
            d[i][j] = 0;
        }
    }
    d[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }

    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += go(n, i);
    }

    cout << (ans % mod) << '\n';


    return 0;
}