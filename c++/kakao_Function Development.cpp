//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while (!progresses.empty()) {
        int n = progresses.size();
        // progress를 진행시킨다.
        for (int i = 0; i < n; i++) {
            progresses[i] += speeds[i];
        }

        // 앞에서부터 100을 넘은 경우 progress를 제거한다.
        int cnt = 0;
        while (!progresses.empty() && progresses[0] >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            cnt++;
        }
        if (cnt > 0) answer.push_back(cnt);
    }

    return answer;
}

int main() {
    auto ans = solution(vector<int>{93, 30, 55}, vector<int>{1, 30, 5});

    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}