//
// Created by SUN on 2018-12-11.
//

#include <iostream>
#include <queue>

using namespace std;

struct RNG {
    unsigned seed;

    RNG() : seed(1983) {};

    unsigned next() {
        unsigned ret = seed;
        seed = (seed * 214013u + 2531011u);

        return ret % 10000 + 1;
    }
};

int solution(int k, int n) {
    RNG rng;

    int rangeSum = 0;
    int ret = 0;
    queue<int> q;
    int now = 0;

    for (int i = 0; i < n; i++) {
        now = rng.next();
        rangeSum += now;
        q.push(now);

        while (k < rangeSum) {
            rangeSum -= q.front();
            q.pop();
        }

        if (k == rangeSum) {
            ret++;
        }

    }

    return ret;
}


int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        int k, n;
        cin >> k >> n;
        int ans = solution(k, n);
        cout << ans << '\n';
    }


    return 0;
}