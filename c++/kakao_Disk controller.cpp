//
// Created by SUN on 2019-01-05.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // 작업 시작시간으로 오름차순으로 정렬한다.
    sort(jobs.begin(), jobs.end(), [](const vector<int> &u, const vector<int> &v) {
        return u[0] < v[0];
    });
    priority_queue<int, vector<int>, greater<int>> minHeap;
    map<int, vector<int>> map1; // key: 걸리는 시간, value: 시작시간
    // map이 필요한 이유는 요청부터 종료까지 시간을 구해주기 위함이다.

    int n = jobs.size();
    int time = 0;
    int job_index = 0;

    while (job_index < n || minHeap.size() > 0) {
        // 현재 time에서 들어갈 수 있는 작업들을 모두 대기작업으로 넣어준다.
        while (job_index < n && jobs[job_index][0] <= time) {
            minHeap.push(jobs[job_index][1]);
            map1[jobs[job_index][1]].push_back(jobs[job_index][0]);
            job_index++;
        }
        // 대기중인 작업큐에서 가장 작은 작업시간이 걸리는 작업을 하나를 빼온다.
        if (!minHeap.empty()) {
            time += minHeap.top();
            int dist = time - map1[minHeap.top()][0];
            map1[minHeap.top()].erase(map1[minHeap.top()].begin(), map1[minHeap.top()].begin() + 1);
            answer += dist;
            minHeap.pop();
        } else {
            // 대기중인 작업이 하나도 없다면, 다음 디스크 시작작업 시간으로 time을 옮겨준다.
            if (job_index < n) {
                time = jobs[job_index][0];
            }
        }

    }

    return answer / n;
}

int main() {
    cout << solution(vector<vector<int>>{{1, 3}}) << '\n';
}