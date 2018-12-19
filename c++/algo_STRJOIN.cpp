//
// Created by SUN on 2018-12-19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> v) {
    int answer = 0;

    multiset<int> ms;

    for (int x: v) {
        ms.insert(x);
    }

    while (ms.size() != 1) {
        auto it = ms.begin();
        int first = *(it++);
        int second = *it;
        ms.insert(first + second);
        answer += (first + second);
        ms.erase(ms.begin(), ++(++ms.begin()));
    }


    return answer;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int ans = solution(n, v);
        cout << ans << '\n';
    }

    return 0;
}