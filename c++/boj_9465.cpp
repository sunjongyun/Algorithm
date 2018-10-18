//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;
        int a[2][n];
        int dp[n][3]; // [col][situation]..
        /* situation explanation
         * If 0, do not select anything
        If 1, select top
        2, select bottom value */


        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        dp[0][0] = 0;
        dp[0][1] = a[0][0];
        dp[0][2] = a[1][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[1][i];
        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
    }


    return 0;
}