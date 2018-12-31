//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    for (long long i = 1; i <= 30000000; i++) {
        if (i * i == n) {
            answer = (i + 1) * (i + 1);
            break;
        }
        if (i * i > n) {
            answer = -1;
            break;
        }
    }
    return answer;
}

int main() {
    cout << solution(50000000000000) << endl;

    return 0;
}