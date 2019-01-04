//
// Created by SUN on 2019-01-05.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long solution(int N) {
    long long dp[81];
    memset(dp, -1, sizeof(dp));
    dp[1]=1;
    dp[2]=1;

    for(int i=3; i<=80; i++){
        dp[i]=dp[i-2]+dp[i-1];
    }

    return dp[N]*4+dp[N-1]*2;
}

int main() {
    cout << solution(80) << '\n';

    return 0;
}