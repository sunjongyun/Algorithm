//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(10, 1);

    for (int i = 1; i < n; i++) {
        vector<int> tmp(10);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                tmp[j] += a[k];
            }

        }

        for (int j = 0; j < 10; j++) {
            a[j] = tmp[j] % 10007;
        }
    }


    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += a[i];
        ans %= 10007;
    }

    cout << ans << '\n';

    return 0;
}