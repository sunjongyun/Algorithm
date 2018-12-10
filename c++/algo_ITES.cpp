//
// Created by SUN on 2018-12-10.
//

#include <iostream>
#include <queue>

using namespace std;

const long long MOD = 4294967296;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int k, cnt;
        cin >> k >> cnt;
        queue<int> q;
        int answer = 0;

        long long ori; // original sign
        int trans; // transform sign

        ori = 1983;
        trans = 1984;
        q.push(trans);

        int sum = trans;
        cnt--;

        while (cnt) {
            if (k == sum) {
                answer++;
                cnt--;
                ori = (ori * 214013 + 2531011) % MOD;
                trans = ori % 10000 + 1;
                sum += trans;
                q.push(trans);
            } else if (k > sum) {
                cnt--;
                ori = (ori * 214013 + 2531011) % MOD;
                trans = ori % 10000 + 1;
                sum += trans;
                q.push(trans);
            } else if (k < sum) {
                sum -= q.front();
                q.pop();
            }
        }

        cout << answer << '\n';
    }


    return 0;
}