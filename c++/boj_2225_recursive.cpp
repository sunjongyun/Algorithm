//
// Created by mac on 2018. 10. 23..
//

#include <iostream>

using namespace std;

long long d[201][201];
const long long mod = 1000000000;

long long go(int n, int k) {
    if (k == 0 || k == 1) return k;

    if (d[n][k] > 0) return d[n][k];

    for (int i = 0; i <= n; i++) {
        d[n][k] += (go(i, k - 1) % mod);
    }

    d[n][k] %= mod;

    return d[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;


    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            d[i][j] = 0;
        }
    }

    long long ans = go(n, k);

    cout << ans << '\n';

    return 0;
}