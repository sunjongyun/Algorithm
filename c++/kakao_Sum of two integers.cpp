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

    for (int i = a; i <= b; i++) {
        answer += i;
    }

    return answer;
}

int main() {

    long long ans = solution(5, 5);
    cout << ans << '\n';

    return 0;
}