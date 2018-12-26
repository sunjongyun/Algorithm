//
// Created by SUN on 2018-12-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int d[1001][10];
int errorD[101][101];

int getPow(int from, int to, vector<int> &v, int val) {
    int ret = 0;
    for (int i = from; i <= to; i++) {
        ret += ((val - v[i]) * (val - v[i]));
    }

    return ret;
}

int getMinError(int from, int to, vector<int> &v) {
    int &ret = errorD[from][to];

    if (ret != -1) return ret;

    ret = INF;

    for (int val = v[from]; val <= v[to]; val++) {
        ret = min(ret, getPow(from, to, v, val));
    }

    return ret;
}


int quantize(int from, int s, vector<int> &v) {
    int n = v.size();

    if (from == n) {
        return 0;
    }

    if (s == 0) {
        return INF;
    }

    int &ret = d[from][s];

    if (ret != -1) return ret;

    ret = INF;

    for (int to = from; to < n; to++) {
        ret = min(ret, getMinError(from, to, v) + quantize(to + 1, s - 1, v));
    }

    return ret;
}


int solution(int n, int s, vector<int> &v) {
    sort(v.begin(), v.end());

    int ret = quantize(0, s, v);


    return ret;
}


int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
        memset(d, -1, sizeof(d));
        memset(errorD, -1, sizeof(errorD));
        int n, s;
        scanf("%d %d", &n, &s);

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        int ans = solution(n, s, v);

        cout << ans << '\n';

    }

    return 0;
}