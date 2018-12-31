//
// Created by SUN on 2019-01-01.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    for (int x: d) {
        if (sum + x <= budget) {
            sum += x;
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{1, 3, 2, 5, 4}, 9) << '\n';

    return 0;
}