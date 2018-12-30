//
// Created by SUN on 2018-12-30.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a > b) swap(a, b);

    long long num = b - a + 1;
    answer += (long long) (b + a) * num / 2;

    return answer;
}

int main() {

    long long ans = solution(5, 3);
    cout << ans << '\n';

    return 0;
}