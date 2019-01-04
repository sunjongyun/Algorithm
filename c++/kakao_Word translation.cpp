//
// Created by SUN on 2019-01-05.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, int> checked;
    queue<string> q;

    q.push(begin);
    checked[begin] = 0;

    while (!q.empty()) {
        string now = q.front();
        q.pop();

        if (now == target) {
            answer = checked[now];
            break;
        }

        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            int sameNum = 0;
            if (checked.count(str) == 0) {
                // 글자가 몇개나 같은지 갯수를 센다
                for (int k = 0; k < str.size(); k++) {
                    if (str[k] == now[k]) sameNum++;
                }
                // 다음 글자로 넘어 갈수 있는지?
                if (sameNum == str.size() - 1) {
                    q.push(str);
                    checked[str] = checked[now] + 1;
                }
            }
        }
    }

    return answer;
}

int main() {
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';

    return 0;
}