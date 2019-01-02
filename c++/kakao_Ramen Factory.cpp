//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = -1;

    int time = 0;
    int index = 0;
    priority_queue<int> max_heap;
    while (time < k) {
        time += stock;
        stock = 0;
        while (index < dates.size() && dates[index] <= time) {
            max_heap.push(supplies[index]);
            index++;
        }
        stock = max_heap.top();
        max_heap.pop();
        answer++;
    }

    return answer;
}

int main() {

    cout << solution(4, vector<int>{4, 10, 15}, vector<int>{20, 5, 10}, 4) << '\n';
    return 0;
}