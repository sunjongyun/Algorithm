//
// Created by SUN on 2018-10-05.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool c[200000];
int d[200000];

int main() {
    int start;
    int end;

    cin >> start >> end;

    queue<int> q;
    q.push(start);
    d[start] = 0;
    c[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) {
                next = now - 1;
                if (next >= 0 && c[next] == false) {
                    q.push(next);
                    c[next] = true;
                    d[next] = d[now] + 1;
                }
            } else if (i == 1) {
                next = now + 1;
                if (next < 200000 && c[next] == false) {
                    q.push(next);
                    c[next] = true;
                    d[next] = d[now] + 1;
                }
            } else if (i == 2) {
                next = now * 2;
                if (next < 200000 && c[next] == false) {
                    q.push(next);
                    c[next] = true;
                    d[next] = d[now] + 1;
                }
            }
        }
    }

    cout << d[end] << '\n';


    return 0;
}