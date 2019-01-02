//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1;
    int right = 1;

    int sum = 1;
    while (right <= n) {
        if (sum == n) {
            answer++;
            sum += ++right;
            sum -= left++;
        } else if (sum < n) {
            right++;
            sum += right;
        } else if (sum > n) {
            sum -= left;
            left++;
        }
    }

    return answer;
}

int main() {
    cout << solution(15) << '\n';
    return 0;
}