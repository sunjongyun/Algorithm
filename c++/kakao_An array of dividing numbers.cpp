//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) answer.push_back(arr[i]);
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0) {
        answer.push_back(-1);
    }

    return answer;
}

int main() {
    auto ans = solution(vector<int>{3, 2, 6}, 10);

    for (int x:ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}