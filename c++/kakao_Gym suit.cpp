//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> they(n + 1, 1);


    for (int i = 0; i < reserve.size(); i++) {
        they[reserve[i]]++;
    }

    for (int i = 0; i < lost.size(); i++) {
        they[lost[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (they[i] == 0) {
            if (i - 1 >= 1 && they[i - 1] == 2) {
                they[i - 1]--;
                they[i]++;
            }
        }
        if (they[i] == 0) {
            if (i + 1 <= n && they[i + 1] == 2) {
                they[i + 1]--;
                they[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (they[i]) answer++;
    }

    return answer;
}

int main() {
    int n = 3;
    vector<int> lost = {3};
    vector<int> reserve = {1};

    auto ans = solution(n, lost, reserve);
    cout << ans << '\n';
    return 0;
}