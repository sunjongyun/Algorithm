//
// Created by SUN on 2018-10-04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int map[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    int ans = 987654321;
    do {
        bool ok = true;
        int sum = 0;

        for (int i = 0; i < n - 1; i++) {
            if (map[v[i]][v[i + 1]] == 0) {
                ok = false;
                break;
            } else {
                sum += map[v[i]][v[i + 1]];
            }
        }

        if (ok == false || map[v[n - 1]][v[0]] == 0) {
            continue;
        } else {
            sum += map[v[n - 1]][v[0]];
            if (ans > sum) {
                ans = sum;
            }
        }

    } while (next_permutation(v.begin() + 1, v.end()));

    cout << ans << '\n';

    return 0;
}