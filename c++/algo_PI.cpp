//
// Created by SUN on 2018-12-25.
//

#include<iostream>
#include <cstring>

using namespace std;

const int INF = 123456789;

int dp[10001];

int getPoint(string sub) {
    int size = sub.size();

    // 1. 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
    int first = sub[0];
    bool is1 = true;
    for (int i = 1; i < size; i++) {
        if (first != sub[i]) {
            is1 = false;
            break;
        }
    }
    if (is1) return 1;

    // 2. 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
    int gap = sub[0] - sub[1];
    bool is2 = true;
    if (gap == -1 || gap == 1) {
        for (int i = 1; i < size - 1; i++) {
            if (gap != sub[i] - sub[i + 1]) {
                is2 = false;
                break;
            }
        }
    } else is2 = false;
    if (is2) return 2;

    // 3. 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
    bool is3 = true;
    if (size == 3) {
        if (sub[0] != sub[2]) is3 = false;
    } else if (size == 4) {
        if (sub[0] != sub[2] || sub[1] != sub[3]) is3 = false;
    } else if (size == 5) {
        if (sub[0] != sub[2] || sub[2] != sub[4] || sub[1] != sub[3]) is3 = false;
    }
    if (is3) return 4;

    // 4. 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
    bool is4 = true;
    gap = sub[0] - sub[1];
    for (int i = 1; i < size - 1; i++) {
        if (gap != (sub[i] - sub[i + 1])) {
            is4 = false;
            break;
        }
    }
    if (is4) return 5;

    // 5. 그 외의 경우 난이도: 10
    return 10;
}


int solution(int start, string &input) {
    int n = input.size();

    if (start == n) {
        return 0;
    }

    if (n - start < 3) {
        return INF;
    }

    int &ret = dp[start];
    if (ret != -1) return ret;

    ret = INF;

    if (start + 3 <= n) {
        ret = min(ret, getPoint(input.substr(start, 3)) + solution(start + 3, input));
    }

    if (start + 4 <= n) {
        ret = min(ret, getPoint(input.substr(start, 4)) + solution(start + 4, input));
    }

    if (start + 5 <= n) {
        ret = min(ret, getPoint(input.substr(start, 5)) + solution(start + 5, input));
    }

    return ret;

}


int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        memset(dp, -1, sizeof(dp));
        string input;
        cin >> input;

        int ans = solution(0, input);

        cout << ans << '\n';
    }


    return 0;
}