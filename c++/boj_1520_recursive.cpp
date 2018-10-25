//
// Created by mac on 2018. 10. 25..
//

#include <iostream>

using namespace std;

int n, m;
long long d[500][500];
int a[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

long long go(int i, int j) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (d[i][j] >= 0) return d[i][j];

    d[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int px = i + dx[k]; // previos x
        int py = j + dy[k]; // previos y

        if (0 <= px && px < n && 0 <= py && py < m) {
            if (a[i][j] < a[px][py]) {
                d[i][j] += go(px, py);
            }
        }
    }

    return d[i][j];
}


int main() {
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            d[i][j] = -1;
        }
    }
    d[0][0] = 1;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    long long ans = go(n - 1, m - 1);

    cout << ans << '\n';


    return 0;
}