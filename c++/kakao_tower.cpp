//
// Created by SUN on 2019-01-01.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> heights) {
    int n = heights.size();
    vector<int> answer(n);
    queue<pair<int, int>> q;
    for (int i = n - 1; i >= 0; i--) {
        int h = heights[i];
        int cnt = q.size();
        while (cnt--) {
            auto now = q.front();
            q.pop();
            if (now.second < h) {
                answer[now.first] = i + 1;
            } else {
                q.push(now);
            }
        }
        q.push({i, heights[i]});
    }

    int cnt = q.size();
    while (cnt--) {
        auto now = q.front();
        q.pop();
        answer[now.first] = 0;
    }

    return answer;
}

int main() {
    auto ans = solution(vector<int>{1, 5, 3, 6, 7, 6, 5});

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}