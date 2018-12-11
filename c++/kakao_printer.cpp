//
// Created by SUN on 2018-12-10.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void rotate(queue<int> &q) {
    int tmp = q.front();
    q.push(tmp);
    q.pop();
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    queue<int> c; // location Only true if location is true, false otherwise
    queue<int> q;
    for (int x: priorities) {
        q.push(x);
    }

    for (int i = 0; i < n; i++) {
        if (location == i) {
            c.push(1); // true
        } else {
            c.push(0); // false
        }
    }

    // Ascending
    sort(priorities.begin(), priorities.end(), greater<int>{});

    for (int now: priorities) {
        answer++;

        while (now != q.front()) {
            rotate(q);
            rotate(c);
        }

        if (c.front()) {
            break;
        }

        q.pop();
        c.pop();
    }


    return answer;
}

int main() {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    int ans = solution(priorities, location);

    cout << ans << '\n';

    return 0;
}