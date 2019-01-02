//
// Created by SUN on 2019-01-03.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void moveDP(int *ori, int *dest) {
    for (int i = 0; i < 4; i++) {
        dest[i] = ori[i];
    }
}

int solution(vector<vector<int> > land) {
    int answer = 0;

    int dp[4];
    memset(dp, 0, sizeof(dp));
    int row = 0;
    while (row < land.size()) {
        int next[4];
        moveDP(dp, next);
        next[0] = max(max(dp[1], dp[2]), dp[3]) + land[row][0];
        next[1] = max(max(dp[0], dp[2]), dp[3]) + land[row][1];
        next[2] = max(max(dp[0], dp[1]), dp[3]) + land[row][2];
        next[3] = max(max(dp[0], dp[1]), dp[2]) + land[row][3];
        moveDP(next, dp);
        row++;
    }

    for (int x: dp) {
        answer = x > answer ? x : answer;
    }
    return answer;
}

int main() {
    cout << solution(vector<vector<int>>{{1, 2, 3, 5},
                                         {5, 6, 7, 8},
                                         {4, 3, 2, 1}}) << '\n';
    return 0;
}