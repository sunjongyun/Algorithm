//
// Created by mac on 2018. 10. 24..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
//    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
        scanf("%d", &a[i]);
    }

    int m;
    cin >> m;
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b[i].first, &b[i].second);
//        cin >> b[i].first >> b[i].second;
    }

    bool d[2001][2001];
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            d[i][j] = false;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == 1) {
                d[i][i] = true;
            }
            if (k == 2) {
                if (i + 1 <= n && a[i] == a[i + 1]) {
                    d[i][i + 1] = true;
                }
            }

            if (i + k - 1 <= n && i + 1 <= n && a[i] == a[i + k - 1] && d[i + 1][i + k - 2]) {
                d[i][i + k - 1] = true;
            }
        }
    }

    for (pair<int, int> p:b) {
        printf("%d\n", d[p.first][p.second]);
//        cout << d[p.first][p.second] << '\n';
    }
    return 0;
}