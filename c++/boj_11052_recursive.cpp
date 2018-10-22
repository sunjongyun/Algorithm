//
// Created by mac on 2018. 10. 22..
//

#include <iostream>

using namespace std;

int d[1001];
int p[1001];

int go(int n) {

    if (n == 0) {
        return 0;
    }

    if (d[n] > 0) return d[n];

    for (int i = 1; i <= n; i++) {
        int tmp = go(n - i);
        if (d[n] < (tmp + p[i])) {
            d[n] = tmp + p[i];
        }
    }

    return d[n];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 1001; i++) {
        d[i] = 0;
        p[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int ans = go(n);

    cout << ans << '\n';

    return 0;
}