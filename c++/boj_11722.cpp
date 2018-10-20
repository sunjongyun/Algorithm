//
// Created by mac on 2018. 10. 19..
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1001];
    int a[n];

    fill_n(dp, 1001, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for (int num: a) {
        int max = 0;
        for (int i = 1000; i > num; i--) {
            if (max < dp[i]) {
                max = dp[i];
            }
        }
        max++;
        dp[num] = max;
    }

    int ans = 0;
    for (int tmp: dp) {
        if (ans < tmp) {
            ans = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}