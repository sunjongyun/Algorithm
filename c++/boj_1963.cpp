//
// Created by SUN on 2018-10-04.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool prime[10000];

void doPrime() {
    for (int i = 2; i < 10000; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j < 10000; j = j + i) {
                prime[j] = true;
            }
        }
    }

    for (int i = 0; i < 10000; i++) {
        prime[i] = !prime[i];
    }
}

int change(int now, int index, int digit) {
    if (index == 0 && digit == 0) {
        return -1;
    }

    string s = to_string(now);
    s[index] = digit + '0';
    return stoi(s);
}

int main() {
    int testcase;
    cin >> testcase;

    doPrime();

    while (testcase--) {
        int start;
        int end;
        bool check[10000];
        int d[10000];

        cin >> start >> end;

        memset(check, false, sizeof(check));
        memset(d, 0, sizeof(d));
        /*int a = 0;
        for (int i = 0; i < 10000; i++) {
            if (check[i]) {
                a++;
            }

        }
        cout << "a: " << a << endl;*/

        queue<int> q;
        q.push(start);
        d[start] = 0;
        check[start] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    int next = change(now, i, j);

                    if (next != -1) {
                        if (prime[next] && check[next] == false) {
                            /*if (next == 1033) {
                                cout << now << ' ' << i << ' ' << j << '\n';
                            }*/
                            q.push(next);
                            d[next] = d[now] + 1;
                            check[next] = true;
                        }
                    }
                }
            }

        }

        cout << d[end] << endl;

    }


    return 0;
}