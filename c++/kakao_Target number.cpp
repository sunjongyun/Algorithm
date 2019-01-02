//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(int cur, int sum, int target, const vector<int> &numbers) {
    if (cur == numbers.size()) {
        if (target == sum) {
            return 1;
        } else return 0;
    }

    int ret = 0;
    ret = dfs(cur + 1, sum + numbers[cur], target, numbers);
    ret += dfs(cur + 1, sum - numbers[cur], target, numbers);

    return ret;
}


int solution(vector<int> numbers, int target) {
    return dfs(0, 0, target, numbers);
}

int main() {
    cout << solution(vector<int>{1, 1, 1, 1, 1}, 3);

    return 0;
}