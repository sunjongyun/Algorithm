//
// Created by SUN on 2018-12-25.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> &v) {
    vector<int> d(n);
    int ret = 0;

    d[0] = 1;

    for (int cur = 1; cur < n; cur++) {
        d[cur] = 1;
        for (int i = cur - 1; i >= 0; i--) {
            if (v[cur] > v[i] && d[cur] < (d[i] + 1)) {
                d[cur] = d[i] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ret = d[i] > ret ? d[i] : ret;
    }

    return ret;
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