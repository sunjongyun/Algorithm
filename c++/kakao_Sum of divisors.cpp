//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        answer += (n % i == 0 ? i : 0);
    }

    return answer;
}

int main() {
    cout << solution(3000) << '\n';

    return 0;
}