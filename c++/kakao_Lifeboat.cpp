//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int l = 0;
    int r = people.size() - 1;

    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;
            r--;
            answer++;
        } else {
            r--;
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{70, 80, 50}, 100) << '\n';

    return 0;
}