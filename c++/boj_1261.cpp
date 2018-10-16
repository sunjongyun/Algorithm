//
// Created by mac on 2018. 10. 16..
//

#include <iostream>
#include <deque>

using namespace std;

int map[101][101];
int d[101][101]; // d[i][j]오는데 벽을 깬 횟수
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool c[101][101];

int main() {
    int m;
    int n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    d[0][0] = 0;

    deque<pair<int, int>> deq;
    deq.push_front({0, 0});

    while (!deq.empty()) {
        int x = deq.front().first;
        int y = deq.front().second;
        deq.pop_front();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (c[nx][ny] == false) {
                    if (map[nx][ny] == 0) {
                        c[nx][ny] = true;
                        deq.push_front({nx, ny});
                        d[nx][ny] = d[x][y];
                    } else if (map[nx][ny] == 1) {
                        c[nx][ny] = true;
                        deq.push_back({nx, ny});
                        d[nx][ny] = d[x][y] + 1;
                    }


                }
            }
        }
    }

    cout << d[n - 1][m - 1] << '\n';
    return 0;
}