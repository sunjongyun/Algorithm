//
// Created by SUN on 2019-01-03.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);

    int size = words.size();
    map<string, int> map1;
    map1[words[0]]++;
    for (int i = 1; i < size; i++) {
        string prev = words[i - 1];
        string now = words[i];
        if (prev[prev.size() - 1] != now[0] || map1.count(now)) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        map1[now]++;
    }

    return answer;
}

int main() {
    auto ans = solution(3, vector<string>{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});

    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}