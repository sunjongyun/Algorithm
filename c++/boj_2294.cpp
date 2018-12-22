//
// Created by mac on 2018. 10. 25..
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;
int dp[10001];

int solve(int n, int k, vector<int> coins) {
    if (k < 0) {
        return INF;
    }

    if (k == 0) {
        return dp[0];
    }

    if (dp[k] != -1) return dp[k];

    dp[k] = INF;
    for (int i = 0; i < n; i++) {
        dp[k] = min(dp[k], solve(n, k - coins[i], coins) + 1);
    }


    return dp[k];
}

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    memset(dp, -1, sizeof(dp)); // initialize -1
    dp[0] = 0;
    int ans = solve(n, k, coins);

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}