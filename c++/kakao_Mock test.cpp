//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void makeSupo(queue<int> &supo1, queue<int> &supo2, queue<int> &supo3) {
    supo1.push(1);
    supo1.push(2);
    supo1.push(3);
    supo1.push(4);
    supo1.push(5);

    supo2.push(2);
    supo2.push(1);
    supo2.push(2);
    supo2.push(3);
    supo2.push(2);
    supo2.push(4);
    supo2.push(2);
    supo2.push(5);

    supo3.push(3);
    supo3.push(3);
    supo3.push(1);
    supo3.push(1);
    supo3.push(2);
    supo3.push(2);
    supo3.push(4);
    supo3.push(4);
    supo3.push(5);
    supo3.push(5);

}

void rotate(queue<int> &q) {
    int tmp = q.front();
    q.pop();
    q.push(tmp);
}

vector<int> solution(vector<int> answers) {
    int n = answers.size();
    vector<int> answer;

    queue<int> supo1;
    queue<int> supo2;
    queue<int> supo3;

    makeSupo(supo1, supo2, supo3);
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;

    for (int i = 0; i < n; i++) {
        int now = answers[i];
        if (now == supo1.front()) {
            ans1++;
        }
        if (now == supo2.front()) {
            ans2++;
        }
        if (now == supo3.front()) {
            ans3++;
        }
        rotate(supo1);
        rotate(supo2);
        rotate(supo3);
    }

    int biggest = max(ans1, max(ans2, ans3));
    if (biggest == ans1) answer.push_back(1);
    if (biggest == ans2) answer.push_back(2);
    if (biggest == ans3) answer.push_back(3);

    return answer;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    auto ans = solution(answers);

    for (int x: ans) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}