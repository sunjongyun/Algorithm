//
// Created by SUN on 2018-10-06.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    int max;
    int start;
    int end;
    int up;
    int down;

    cin >> max >> start >> end >> up >> down;

    map<int, int> d;
    queue<int> q;
    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        int next;
        if (now + up <= max) {
            next = now + up;
            if (d.count(next) == 0) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }

        if (now - down >= 1) {
            next = now - down;
            if (d.count(next) == 0) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }

    if (start == end) {
        cout << 0 << '\n';
    } else {
        if (d.count(end) == 0) {
            cout << "use the stairs" << '\n';
        } else {
            cout << d[end] << '\n';
        }
    }


    return 0;
}