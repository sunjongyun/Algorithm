//
// Created by mac on 2018. 10. 19..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n];

    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > dp[i - 1]) {
            dp[i] = a[i - 1] + a[i];
        } else {
            dp[i] = dp[i - 1] + a[i];
        }
    }

    int ans = -987654321;
    for (int i = 0; i < n; i++) {
        ans = max({a[i], dp[i], ans});
    }

    cout << ans << '\n';
    return 0;
}