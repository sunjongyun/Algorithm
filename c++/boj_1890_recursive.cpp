//
// Created by mac on 2018. 10. 24..
//

#include <iostream>

using namespace std;

long long d[101][101];
int a[101][101];

long long go(int n, int m) {
    if (n == 1 && m == 1) {
        return 1;
    }

    if (d[n][m] != -1) return d[n][m];

    d[n][m] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i][m] == (n - i)) {
            d[n][m] += go(i, m);
        }
    }

    for (int j = 1; j < m; j++) {
        if (a[n][j] == (m - j)) {
            d[n][m] += go(n, j);
        }
    }

    return d[n][m];
}


int main() {
    int n;
    cin >> n;

    // initialize d[][]
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            d[i][j] = -1;
            a[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    long long ans = go(n, n);

    cout << ans << '\n';


    return 0;
}