//
// Created by mac on 2018. 10. 17..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int seek;
    int n;
    int m;

    cin >> seek >> n >> m;

    vector<int> a1;
    vector<int> a2;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a1.push_back(tmp);
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        a2.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        a1.push_back(a1[i]);
    }
    for (int i = 0; i < m; i++) {
        a2.push_back(a2[i]);
    }

    vector<int> v1, v2;
    v1.push_back(0);
    v2.push_back(0);

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < (i + n - 1); ++j) {
            sum += a1[j];
            v1.push_back(sum);
        }
    }
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += a1[i];
    }
    v1.push_back(tmp);

    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = i; j < (i + m - 1); ++j) {
            sum += a2[j];
            v2.push_back(sum);
        }
    }
    tmp = 0;
    for (int i = 0; i < m; i++) {
        tmp += a2[i];
    }
    v2.push_back(tmp);

    sort(v2.begin(), v2.end());
    int ans = 0;
    for (int num: v1) {
        auto it = equal_range(v2.begin(), v2.end(), seek - num);
        ans += (it.second - it.first);
    }

    cout << ans << '\n';

    return 0;
}