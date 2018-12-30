//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000000;

int solution(int n) {
    int answer = 0;

    vector<int> prime(MAX + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            answer++;
            for (int j = i * 2; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }

    return answer;
}

int main() {

    cout << solution(5) << '\n';

    return 0;
}