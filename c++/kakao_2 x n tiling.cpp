//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;

int solution(int n) {
    long long dp[60001];
    memset(dp, -1, sizeof(dp));

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 60000; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    return dp[n];
}

int main() {
    cout << solution(4) << '\n';
    return 0;
}