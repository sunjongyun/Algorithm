//
// Created by SUN on 2018-12-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[101][101];

int matchMemorized(int w_index, int s_index, string pattern, string str) {

    if (w_index == pattern.size()) {
        if (s_index == str.size()) {
            return 1;
        } else return 0;
    }

    int &ret = dp[w_index][s_index];

    if (ret != -1) return ret;

    ret = 0;

    if (w_index < pattern.size() && s_index < str.size() &&
        (pattern[w_index] == str[s_index] || pattern[w_index] == '?')) {
        ret = matchMemorized(w_index + 1, s_index + 1, pattern, str);
    }

    if (pattern[w_index] == '*') {
        ret = matchMemorized(w_index + 1, s_index, pattern, str) ||
              (s_index < str.size() && matchMemorized(w_index, s_index + 1, pattern, str));
    }

    return ret;

}


int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        string pattern; // pattern
        string str;
        cin >> pattern;
        cin >> n;
        vector<string> v;

        for (int i = 0; i < n; i++) {
            memset(dp, -1, sizeof(dp));
            cin >> str;
            int ans = matchMemorized(0, 0, pattern, str);
            if (ans == 1) {
                v.push_back(str);
            }
        }

        sort(v.begin(), v.end()); // In alphabetical order

        for (string x: v) {
            cout << x << '\n';
        }

    }


    return 0;
}