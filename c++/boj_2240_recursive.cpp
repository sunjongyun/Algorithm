//
// Created by SUN on 2018-10-26.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[10001];
int d[10001][31];
int n, m;

int go(int sec, int turn) {
    if (sec > n || turn > m) {
        return 0;
    }

    if (d[sec][turn] != -1) return d[sec][turn];

    int &ans = d[sec][turn];

    int where = turn % 2 + 1;
    ans = max(go(sec + 1, turn), go(sec + 1, turn + 1)) + (where == a[sec] ? 1 : 0);

    return ans;
}


int main() {
    memset(a, 0, sizeof(a));
    memset(d, -1, sizeof(d));

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = max(go(1, 0), go(1, 1));

    printf("%d", ans);


    return 0;
}