//
// Created by SUN on 2018-10-05.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool check[201][201][201];

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    set<int> ans;
    ans.insert(c);
    check[0][0][c] = true;

    queue<int> q1;
    queue<int> q2;
    queue<int> q3;

    q1.push(0);
    q2.push(0);
    q3.push(c);

    while (!q1.empty()) {
        int now1 = q1.front();
        int now2 = q2.front();
        int now3 = q3.front();
        q1.pop();
        q2.pop();
        q3.pop();

        for (int i = 0; i < 6; i++) {
            int next1;
            int next2;
            int next3;
            if (i == 0) { // A->B로 붇는 방법
                if (now1 > b - now2) {
                    next1 = now1 - (b - now2);
                    next2 = b;
                    next3 = now3;
                } else {
                    next1 = 0;
                    next2 = now1 + now2;
                    next3 = now3;
                }
            } else if (i == 1) { // A->C로
                if (now1 > c - now3) {
                    next1 = now1 - (c - now3);
                    next2 = now2;
                    next3 = c;
                } else {
                    next1 = 0;
                    next2 = now2;
                    next3 = now1 + now3;
                }
            } else if (i == 2) { // B->A로
                if (now2 > a - now1) {
                    next1 = a;
                    next2 = now2 - (a - now1);
                    next3 = now3;
                } else {
                    next1 = now1 + now2;
                    next2 = 0;
                    next3 = now3;
                }
            } else if (i == 3) { // B->C로
                if (now2 > c - now3) {
                    next1 = now1;
                    next2 = now2 - (c - now3);
                    next3 = c;
                } else {
                    next1 = now1;
                    next2 = 0;
                    next3 = now2 + now3;
                }
            } else if (i == 4) { // C->A
                if (now3 > a - now1) {
                    next1 = a;
                    next2 = now2;
                    next3 = now3 - (a - now1);
                } else {
                    next1 = now1 + now3;
                    next2 = now2;
                    next3 = 0;
                }
            } else if (i == 5) { // C->B
                if (now3 > b - now2) {
                    next1 = now1;
                    next2 = b;
                    next3 = now3 - (b - now2);
                } else {
                    next1 = now1;
                    next2 = now2 + now3;
                    next3 = 0;
                }
            }
            if (check[next1][next2][next3] == false) {
                q1.push(next1);
                q2.push(next2);
                q3.push(next3);
                check[next1][next2][next3] = true;
                if (next1 == 0) {
                    ans.insert(next3);
                }
            }
        }

    }


    for (int x: ans) {
        cout << x << ' ';
    }

    return 0;
}
