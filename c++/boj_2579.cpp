//
// Created by mac on 2018. 10. 19..
//

#include <iostream>
#include <algorithm>

using namespace std;

static const int pp = 0; // previous previous
static const int p = 1;  // previous

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][pp] = a[0];
    dp[0][p] = a[0];
    dp[1][pp] = a[1];
    dp[1][p] = dp[0][pp] + a[1];
    for (int i = 2; i < n; i++) {
        int bigger = max(dp[i - 2][pp], dp[i - 2][p]);
        dp[i][pp] = bigger + a[i];
        dp[i][p] = dp[i - 1][pp] + a[i];
    }

    cout << max(dp[n - 1][pp], dp[n - 1][p]) << '\n';

    return 0;
}