//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int smallest = *min_element(arr.begin(), arr.end());
    auto it = find(arr.begin(), arr.end(), smallest);
    arr.erase(it);
    if (arr.size() == 0) arr.push_back(-1);
    return arr;
}

int main() {

    auto ans = solution(vector<int>{10});

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}