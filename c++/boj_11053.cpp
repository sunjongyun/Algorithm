//
// Created by mac on 2018. 10. 18..
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[1001];

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < 1001; i++) {
        dp[i] = 0;
    }

    dp[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        int max = 0;
        int index = a[i];
        for (int j = 1; j < index; j++) {
            if (dp[j] > max) {
                max = dp[j];
            }
        }
        max += 1;
        dp[index] = max;
    }

    int max = 0;
    for (int i = 0; i < 1001; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    cout << max << '\n';


    return 0;
}