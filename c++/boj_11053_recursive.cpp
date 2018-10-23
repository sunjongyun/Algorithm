//
// Created by mac on 2018. 10. 23..
//

#include <iostream>

using namespace std;

int d[1001]; // memoization
int a[1001];

int go(int n) {
    if (n == 1) {
        return 1;
    }

    if (d[n] > 0) return d[n];
    d[n] = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] < a[n]) {
            int tmp = go(i);
            if (d[n] < tmp + 1) d[n] = tmp + 1;
        }
    }

    return d[n];
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < 1001; i++) {
        d[i] = 0;
        a[i] = 0;
    }


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = go(i);
        if (tmp > ans) {
            ans = tmp;
        }
    }

    cout << ans << '\n';
    return 0;
}