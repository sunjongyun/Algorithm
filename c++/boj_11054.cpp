//
// Created by mac on 2018. 10. 19..
//

#include <iostream>


int l = 0; // The increasing order is from left to right
int r = 1; // The increasing order is from right to left

using namespace std;

int main() {
    int n;
    cin >> n;


    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[1001][2];
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = 0;
        }
    }

    int index = 0;
    for (int now: a) {

        int max = 0;
        for (int i = 0; i < index; i++) {
            if (a[i] < now) {
                if (max < dp[i][l]) {
                    max = dp[i][l];
                }
            }

        }
        dp[index][l] = max + 1;
        index++;
    }

    for (int k = n - 1; k >= 0; k--) {
        int now = a[k];
        int max = 0;
        for (int i = n - 1; i > k; i--) {
            if (a[i] < now) {
                if (max < dp[i][r]) {
                    max = dp[i][r];
                }
            }

        }
        dp[k][r] = max + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < dp[i][l] + dp[i][r]) {
            ans = dp[i][l] + dp[i][r];
        }
    }

    cout << ans - 1 << '\n';
    return 0;
}