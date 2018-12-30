//
// Created by SUN on 2018-12-31.
//

#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    while (n / 10) {
        answer += (n % 10);
        n /= 10;
    }
    answer += n;

    return answer;
}

int main() {

    cout << solution(987) << endl;

    return 0;
}