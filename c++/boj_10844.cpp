//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000000000;

int main() {
    int n;
    cin >> n;

    vector<long long> a(10);
    for (int i = 1; i < 10; i++) {
        a[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        vector<long long> tmp(10);
        for (int j = 0; j < 10; j++) {
            if (j - 1 >= 0) {
                tmp[j] = (a[j - 1] + a[j + 1]) % MAX;
            } else if (j + 1 >= 10) {
                tmp[j] = a[j - 1] % MAX;
            } else {
                tmp[j] = a[j + 1] % MAX;
            }
        }
        copy(tmp.begin(), tmp.end(), a.begin());
    }

    long long ans = 0;
    for (int num: a) {
        ans += num;
        ans %= MAX;
    }

    cout << ans << '\n';


    return 0;
}