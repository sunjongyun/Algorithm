//
// Created by mac on 2018. 10. 4..
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool prime[10000];
bool c[10001];
int d[10001];

void do_prime() {
    for (int i = 2; i < 10000; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j < 10000; j += i) {
                prime[j] = true;
            }
        }
    }

    for (int i = 0; i < 10000; i++) {
        prime[i] = !prime[i];
    }
}

int change(int num, int index, int digit) {
    if (index == 0 && digit == 0) return -1;

    string s = to_string(num);
    s[index] = digit + '0';
    return stoi(s);
}


int main() {

    do_prime(); // 에라토스테네스의 체를 사용하여 소수를 구한다.


    int testcase;
    cin >> testcase;
    while (testcase--) {
        int start;
        int end;
        cin >> start >> end;

        memset(c, false, sizeof(c));
        memset(d, 0, sizeof(d));

        queue<int> q;
        q.push(start);
        c[start] = true;
        d[start] = 0;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            //한자리씩 바꿈
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    int next = change(now, i, j);
                    if (next != -1) {
                        if (prime[next] && c[next] == false) {
                            q.push(next);
                            c[next] = true;
                            d[next] = d[now] + 1;
                        }
                    }
                }
            }
        }

        cout << d[end] << '\n';

    }


    return 0;
}