//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // 최소힙 구현
    // push, delete, find 모두 log(n)
    priority_queue<int, vector<int>, greater<int>> sortedScov;

    for (int x : scoville) sortedScov.push(x);

    while (sortedScov.size() != 1 && sortedScov.top() < K) {
        answer++;
        int first = sortedScov.top();
        sortedScov.pop();
        int second = sortedScov.top();
        sortedScov.pop();
        sortedScov.push(first + second * 2);
    }

    if (sortedScov.top() < K) return -1;
    return answer;
}

int main() {
    cout << solution(vector<int>{1, 1, 1, 1, 1, 1}, 100) << '\n';

    return 0;
}