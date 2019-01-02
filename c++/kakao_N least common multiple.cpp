
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer;
    if (arr.size() == 1) return arr[0];

    answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int g = __gcd(answer, arr[i]);
        answer = answer * arr[i] / g;
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{2, 6, 8, 14}) << '\n';
    return 0;
}