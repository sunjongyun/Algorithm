//
// Created by SUN on 2018-10-26.
//

#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[501];
int d[501][501];
int s[501];

int go(int i, int j) {
    if (i == j) return 0; // base value

    if (d[i][j] != 0) return d[i][j]; //memoization

    for (int k = i; k <= j - 1; k++) {
        int tmp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];

        if (d[i][j] == -1 || d[i][j] > tmp) {
            d[i][j] = tmp;
        }
    }

    return d[i][j];
}

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        memset(d, -1, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }

        int ans = go(1, n);

        cout << ans << '\n';

    }


    return 0;
}