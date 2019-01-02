//
// Created by SUN on 2019-01-03.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums) {
    int n = nums.size() / 2;
    map<int, int> map1;
    for (int x: nums) {
        map1[x]++;
    }

    return n > map1.size() ? map1.size() : n;
}

int main() {
    cout << solution(vector<int>{3, 3, 3, 2, 2, 2}) << '\n';
    return 0;
}