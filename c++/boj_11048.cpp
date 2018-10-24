//
// Created by SUN on 2018-10-23.
//

#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, -1, -1};
int dy[] = {-1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    d[0][0] = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int max = 0;
            for (int k = 0; k < 3; k++) {
                int px = i + dx[k];
                int py = j + dy[k];
                if (0 <= px && 0 <= py) {
                    if (max < d[px][py]) {
                        max = d[px][py];
                    }
                }
            }

            d[i][j] = max + a[i][j];

        }
    }

    cout << d[n - 1][m - 1] << '\n';

    return 0;
}