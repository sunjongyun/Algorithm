//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int cnt = 500;

    while (num != 1 && cnt--) {
        if (num & 1) num = num * 3 + 1;
        else num /= 2;
        answer++;
    }

    return answer == 500 ? -1 : answer;
}

int main() {
    cout << solution(1) << '\n';

    return 0;
}