//
// Created by SUN on 2018-12-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * The person who takes the longest time to eat eats first.
 * */
int solution(int n, vector<int> m, vector<int> e) {
    int answer;

    int mtotal = 0;
    for (int i = 0; i < n; i++) {
        mtotal += m[i];
    }

    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++) {
        data.push_back({m[i], e[i]});
    }

    sort(data.begin(), data.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
        if (u.second > v.second) {
            return true;
        } else
            return false;
    });

    int biggest = 0;
    int remain = mtotal;
    for (int i = 0; i < n; i++) {
        remain -= data[i].first;

        if (biggest < data[i].second - remain) {
            biggest = data[i].second - remain;
        }
    }

    answer = mtotal + biggest;

    return answer;
}


int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        vector<int> m(n);
        vector<int> e(n);
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }


        int ans = solution(n, m, e);
        cout << ans << '\n';

    }

    return 0;
}