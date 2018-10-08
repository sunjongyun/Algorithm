//
// Created by SUN on 2018-10-05.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool c[10000];
int from[10000];
char how[10000];


// from[end]
void print(int start, int end) {

    if (from[end] == -1) {
        return;
    }
    print(start, from[end]);

    cout << how[end];
}

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int start;
        int end;
        cin >> start >> end;

        memset(c, false, sizeof(c));
        memset(from, 0, sizeof(from));
        memset(how, 0, sizeof(how));

        c[start] = true;
        from[start] = -1;
        how[start] = 0;

        queue<int> q;
        q.push(start);


        while (!q.empty()) {
            int now = q.front();
            q.pop();

            int next;

            // D를 입력했을시
            next = now * 2;
            if (next > 9999) {
                next = (next % 10000);
            }
            if (c[next] == false) {
                c[next] = true;
                from[next] = now;
                how[next] = 'D';
                q.push(next);
            }

            //S를 입력했을시
            if (now == 0) {
                next = 9999;
            } else {
                next = now - 1;
            }
            if (c[next] == false) {
                c[next] = true;
                from[next] = now;
                how[next] = 'S';
                q.push(next);
            }

            //L을 입력했을시
            next = ((now * 10) % 10000) + (now / 1000);
            if (c[next] == false) {
                c[next] = true;
                from[next] = now;
                how[next] = 'L';
                q.push(next);
            }

            //R를 입력했을시
            next = (now / 10) + ((now % 10) * 1000);
            if (c[next] == false) {
                c[next] = true;
                from[next] = now;
                how[next] = 'R';
                q.push(next);
            }

        }

        print(start, end);
        cout << '\n';
    }


    return 0;
}