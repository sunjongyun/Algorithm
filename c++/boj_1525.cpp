//
// Created by SUN on 2018-10-05.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    int n = 3;

    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if (input == 0) {
                input = 9;
            }
            start = start * 10 + input;
        }
    }

    map<int, int> dist;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int now_num = q.front();
        q.pop();
        string now = to_string(now_num);

        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                string next = now;
                swap(next[3 * x + y], next[3 * nx + ny]);
                int next_num = stoi(next);
                if (dist.count(next_num) == 0) {
                    q.push(next_num);
                    dist[next_num] = dist[now_num] + 1;
                }
            }
        }
    }

    if (dist.count(123456789) == 0) {
        cout << -1 << '\n';
    } else {
        cout << dist[123456789] << '\n';
    }


    return 0;
}