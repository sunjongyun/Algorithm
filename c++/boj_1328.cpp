//
// Created by SUN on 2018-10-26.
//

#include <iostream>

using namespace std;

long long d[101][101][101];
long long mod = 1000000007LL;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    d[1][1][1] = 1LL;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            for (int k = 1; k <= r; k++) {
                d[i][j][k] = d[i - 1][j - 1][k] + d[i - 1][j][k - 1] + d[i - 1][j][k] * (n - 2);
                d[i][j][k] %= mod;
            }
        }
    }

    cout << d[n][l][r] << '\n';

    return 0;
}