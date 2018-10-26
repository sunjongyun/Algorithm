//
// Created by SUN on 2018-10-26.
//

#include <iostream>
#include <cstring>

using namespace std;
int d[501][501];
pair<int, int> a[501];

int go(int i, int j) {
    if (i == j) return 0;

    if (d[i][j] != -1) return d[i][j];

    for (int k = i; k <= j - 1; k++) {
        int tmp = go(i, k) + go(k + 1, j) + a[i].first * a[k].second * a[j].second;
        if (d[i][j] == -1 || d[i][j] > tmp) {
            d[i][j] = tmp;
        }
    }

    return d[i][j];
}

int main() {
    int n;

    cin >> n;

    memset(d, -1, sizeof(d));
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int ans = go(1, n);

    cout << ans << '\n';


    return 0;
}