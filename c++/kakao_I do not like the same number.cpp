//
// Created by SUN on 2018-12-30.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            answer.push_back(arr[i]);
        }
    }

    answer.push_back(arr[n-1]);

    return answer;
}

int main() {
    auto ans = solution(vector<int>{4,4,4,3,3});
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}