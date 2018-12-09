//
// Created by SUN on 2018-12-10.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> p; //priority_queue
    queue<int> q; //queue
    queue<bool> c; //checked
    for (int i = 0; i < priorities.size(); i++) {
        p.push(priorities[i]);
        q.push(priorities[i]);
        if (i == location) {
            c.push(true);
        } else {
            c.push(false);
        }
    }


    int n = p.size();
    bool isFind = false;

    for (int i = 0; i < n; i++) {
        int nowP = p.top();
        p.pop();

        while (true) {
            int nowQ = q.front();
            bool nowC = c.front();
            if (nowP == q.front()) {
                if (nowC) {
                    isFind = true;
                }
                q.pop();
                c.pop();
                answer++;
                break;
            } else {
                q.pop();
                c.pop();
                q.push(nowQ);
                c.push(nowC);
            }
        }

        if (isFind) {
            break;
        }

    }

    return answer;
}

int main() {
//    vector<int> priorities = {2, 1, 3, 2};
//    int location = 2;
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    int ans = solution(priorities, location);

    cout << ans << '\n';

    return 0;
}