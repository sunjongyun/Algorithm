//
// Created by mac on 2018. 10. 23..
//

#include <iostream>
#include <math.h>

using namespace std;

int d[100001];

int go(int n) {
    if (n == 0) return 0;

    if (d[n] > 0) return d[n];

    d[n] = 987654321;
    for (int i = 1; i <= sqrt(n); i++) {
        int tmp = go(n - pow(i, 2));
        if (d[n] > tmp + 1) d[n] = tmp + 1;
    }

    return d[n];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 100001; i++) {
        d[i] = 0;
    }

    int ans = go(n);


    cout << ans << '\n';

    return 0;
}
