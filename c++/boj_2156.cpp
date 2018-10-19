//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <algorithm>

using namespace std;

const int no = 0; //not selected
const int con = 1; //previos + current
const int neww = 2; // except previos, put in current

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int dp[n][3];
    dp[0][no] = 0;
    dp[0][con] = 0;
    dp[0][neww] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i][no] = max({dp[i - 1][no], dp[i - 1][con], dp[i - 1][neww]});
        dp[i][con] = max(dp[i - 1][no], dp[i - 1][neww]) + a[i];
        dp[i][neww] = dp[i - 1][no] + a[i];
    }

    cout << max({dp[n - 1][no], dp[n - 1][con], dp[n - 1][neww]}) << '\n';


    return 0;
}