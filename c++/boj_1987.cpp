//
// Created by mac on 2018. 10. 8..
//
#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;
int m;

int go(vector<string> &board, vector<bool> &check, int nowX, int nowY) {
    int ans = 0;

    for (int k = 0; k < 4; k++) {
        int nextX = nowX + dx[k];
        int nextY = nowY + dy[k];

        if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
            if (check[board[nextX][nextY] - 'A'] == false) {
                check[board[nextX][nextY] - 'A'] = true;
                int next = go(board, check, nextX, nextY);
                if (ans < next) {
                    ans = next;
                }
                check[board[nextX][nextY] - 'A'] = false;
            }
        }

    }

    return ans + 1;
}

int main() {

    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<bool> check(26);
    check[board[0][0] - 'A'] = true;
    int ans = go(board, check, 0, 0);

    cout << ans << '\n';

    return 0;
}
