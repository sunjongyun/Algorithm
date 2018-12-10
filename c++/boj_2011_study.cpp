//
// Created by SUN on 2018-12-10.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int d[5001];

int solution(string str, int cur) {
    int oneDigit = stoi(str.substr(cur, 1));
    if (cur == 0) {
        if (1 <= oneDigit && oneDigit <= 9) return 1;
        else return 0;
    }

    int twoDigit = stoi(str.substr(cur - 1, 2));
    if (cur == 1) {
        int ret = 0;
        if (10 <= twoDigit && twoDigit <= 26) ret++;
        if (1 <= oneDigit && oneDigit <= 9) ret += solution(str, 0);
        return ret;
    }

    if (d[cur] != -1) return d[cur]; // memoization

    d[cur] = 0;


    if (1 <= oneDigit && oneDigit <= 9) {
        d[cur] += (solution(str, cur - 1)%1000000);
    }

    if (10 <= twoDigit && twoDigit <= 26) {
        d[cur] += (solution(str, cur - 2)%1000000);
    }

    d[cur]%=1000000;

    return d[cur];
}

int main() {
    string input;
    cin >> input;

    //initialize
    memset(d, -1, sizeof(d));

    int n = input.length() - 1;
    int ans = solution(input, n);

    cout << ans << '\n';

    return 0;
}