//
// Created by SUN on 2018-10-26.
//

#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    long long a[n + 1];
    long long d[n + 1];
    a[1] = 1;
    a[2] = 3;

    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + 2 * a[i - 2];
    }

    d[1] = 1LL;
    d[2] = 3LL;

    for (int i = 3; i <= n; i++) {
        long long b = 0;
        if (i % 2 == 1) b = a[(i - 1) / 2];
        else b = a[(i / 2)] + 2 * a[(i - 2) / 2];

        d[i] = (a[i] + b) / 2;
    }

    cout << d[n] << '\n';

    return 0;
}