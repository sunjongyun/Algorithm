//
// Created by SUN on 2018-12-27.
//

#include <iostream>

#define ll long long
using namespace std;

ll patty[51]; // N level patty's size
ll level[51]; // N level burger's size

ll solution(ll N, ll X) {

    if (N == 0) {
        return 1;
    }

    ll ret = 0;

    ll part1 = 1;
    ll part2 = part1 + 1;
    ll part3 = part2 + level[N - 1];
    ll part4 = part3 + 1;
    ll part5 = part4 + level[N - 1];

    if (part1 <= X && X < part2) {
        ret = 0;
    } else if (part2 <= X && X < part3) {
        ret = solution(N - 1, X - 1);
    } else if (part3 <= X && X < part4) {
        ret = patty[N - 1] + 1;
    } else if (part4 <= X && X < part5) {
        ret = patty[N - 1] + 1 + solution(N - 1, X - part4 + 1);
    } else {
        ret = patty[N - 1] * 2 + 1;
    }

    return ret;
}


int main() {
    long long N, X;
    cin >> N >> X;

    patty[0] = 1;
    for (int i = 1; i <= 50; i++) {
        patty[i] = patty[i - 1] * 2 + 1;
    }
    level[0] = 1;
    for (int i = 1; i <= 50; i++) {
        level[i] = 3 + level[i - 1] * 2;
    }
    ll ans = solution(N, X);

    cout << ans << '\n';

    return 0;
}