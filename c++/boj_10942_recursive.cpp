//
// Created by mac on 2018. 10. 24..
//

#include <iostream>

using namespace std;

int a[2001];
int d[2001][2001];

int go(int s, int e) {
    if (s == e) { // 길이가 1인 경우
        return 1;
    }
    if ((e - s + 1) == 2) { //길이가 2인경우
        if (a[s] == a[e]) {
            return 1;
        } else return 0;
    }

    if (d[s][e] != -1) return d[s][e]; //memoization

    if (a[s] != a[e]) return d[s][e] = 0;
    else return d[s][e] = go(s + 1, e - 1);
}

int main() {
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            d[i][j] = -1;
        }
        a[i] = 0;
    }

    int n;
    //cin >> n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);
//    cin >> m;

    while (m--) {
        pair<int, int> p;
//        cin >> p.first >> p.second;
        scanf("%d %d", &p.first, &p.second);
        int ans = go(p.first, p.second);
//        cout << ans << '\n';
        printf("%d\n", ans);
    }


    return 0;
}