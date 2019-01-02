//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(int n) {
    int f[100001];
    memset(f, -1, sizeof(f));

    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        f[i] = (f[i - 2] + f[i - 1]) % 1234567;
    }

    return f[n];
}

int main() {
    cout << solution(5) << '\n';

    return 0;
}