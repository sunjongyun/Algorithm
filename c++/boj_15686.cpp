//
// Created by SUN on 2018-10-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int doSize(vector<pair<int, int>> &tmp, vector<pair<int, int>> &h) {
    int t_size = tmp.size();
    int h_size = h.size();
    int ans = 0;

    for (int i = 0; i < h_size; i++) {
        int min = 987654321;
        for (int j = 0; j < t_size; j++) {
            int x_gap = abs(h[i].first - tmp[j].first);
            int y_gap = abs(h[i].second - tmp[j].second);
            int total = x_gap + y_gap;
            if (min > total) {
                min = total;
            }
        }
        ans += min;
    }

    return ans;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> c; //chicken
    vector<pair<int, int>> h; //house

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                h.push_back({i, j});
            } else if (a[i][j] == 2) {
                c.push_back({i, j});
            }
        }
    }

    //permutation 돌릴 string을 만들자.
    int zero_num = c.size() - m;
    int one_num = m;
    string s;
    for (int i = 0; i < zero_num; i++) {
        s.push_back('0');
    }
    for (int i = 0; i < one_num; i++) {
        s.push_back('1');
    }

    int ans = 987654321;
    //치킨집의 부분집합을 만들자
    do {
        vector<pair<int, int>> tmp; // 치킨집 부분 집합
        for (int i = 0; i < c.size(); i++) {
            if (s[i] == '1') {
                tmp.push_back(c[i]);
            }
        }
        int res = doSize(tmp, h);
        if (ans > res) {
            ans = res;
        }
    } while (next_permutation(s.begin(), s.end()));


    cout << ans << '\n';

    return 0;
}