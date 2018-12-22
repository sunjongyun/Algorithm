//
// Created by SUN on 2018-12-22.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int left, int right, const int n, const vector<int> &v) {
    int ret = 0;
    if (left == right) {
        return v[left];
    }

    int half = (left + right) / 2;
    ret = max(solution(left, half, n, v), solution(half + 1, right, n, v));

    int curL = half;
    int curR = half + 1;
    int width = 2;
    int height = min(v[curL], v[curR]);
    int area = height * width;

    while (left < curL || curR < right) {
        width++;
        if (curR < right && (left == curL || left < curL && v[curR + 1] >= v[curL - 1])) {
            curR++;
            height = min(v[curR], height);
            area = max(area, height * width);
        } else {
            curL--;
            height = min(v[curL], height);
            area = max(area, height * width);
        }
    }

    ret = max(area, ret);

    return ret;
}


int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        int ans = solution(0, n - 1, n, v);
        printf("%d\n", ans);
    }


    return 0;
}