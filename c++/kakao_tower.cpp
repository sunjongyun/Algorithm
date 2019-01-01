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
    queue<pair<int, int>> q; // 아직 송신할 곳을 못찾은 탑들이 저장되어 있다.
    // 탑의 오른쪽부터 시작한다.
    for (int i = n - 1; i >= 0; i--) {
        int h = heights[i]; // 현재탑의 높이
        int cnt = q.size();
        // [i]의 오른쪽에 있는 탑들 중에서 아직 송신하지 못한 탑들은 queue안에 담겨있다.
        // 아직 송신못한 탑중에 송신 할수 있는 탑이 있는지 찾는다.
        while (cnt--) {
            auto now = q.front();
            q.pop();
            // 송신할 곳을 찾음
            if (now.second < h) {
                answer[now.first] = i + 1;
            } else { // 송신할 곳을 못찾음
                q.push(now);
            }
        }
        // 현재의 탑을 큐에 넣어준다.
        q.push({i, heights[i]});
    }

    // 아직 송신할 곳을 못찾은 탑들은 0을 answer에 넣어준다.
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