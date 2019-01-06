//
// Created by SUN on 2019-01-07.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void clean(priority_queue<int> &a, priority_queue<int, vector<int>, greater<int>> &b) {
    while (!a.empty()) {
        a.pop();
    }
    while (!b.empty()) {
        b.pop();
    }
}

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int num = 0;
    for (string x: operations) {
        if (x == "D 1") {
            if (num > 0) {
                max_heap.pop();
                num--;
                if (num == 0) clean(max_heap, min_heap);
            }
        } else if (x == "D -1") {
            if (num > 0) {
                min_heap.pop();
                num--;
                if (num == 0) clean(max_heap, min_heap);
            }
        } else { // I 숫자 인경우
            string str = x.substr(2);
            int val = stoi(str);
            max_heap.push(val);
            min_heap.push(val);
            num++;
        }
    }

    return max_heap.size() == 0 ? vector<int>{0, 0} : vector<int>{max_heap.top(), min_heap.top()};
}

int main() {
    auto ans = solution(vector<string>{"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}