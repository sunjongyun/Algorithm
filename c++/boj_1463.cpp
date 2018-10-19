//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dist[1000001];
    fill_n(dist, 1000001, -1); // dist[index]가 -1이면 방문 x 그 외의 값이면 index까지 가는데 걸리는 시간

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now % 3 == 0 && dist[now / 3] == -1) {
            q.push(now / 3);
            dist[now / 3] = dist[now] + 1;
        }
        if (now % 2 == 0 && dist[now / 2] == -1) {
            q.push(now / 2);
            dist[now / 2] = dist[now] + 1;
        }
        if (now - 1 > 0 && dist[now - 1] == -1) {
            q.push(now - 1);
            dist[now - 1] = dist[now] + 1;
        }
    }

    cout << dist[1] << '\n';

    return 0;
}