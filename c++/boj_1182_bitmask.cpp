//
// Created by SUN on 2018-10-07.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int s;
    cin >> n >> s;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        int tmp = i;
        for (int j = 0; j < n; j++) {
            if (tmp & 1) {
                sum += v[j];
            }
            tmp = (tmp >> 1);
        }

        if (sum == s) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}