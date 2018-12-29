//
// Created by SUN on 2018-12-29.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;

    for (int i = 0; i < participant.size(); i++) {
        if (m.count(participant[i]) == 0) {
            m.insert({participant[i], 1});
        } else {
            m[participant[i]]++;
        }
    }

    for (int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }

    for (auto x: m) {
        if (x.second == 1) {
            answer = x.first;
        }
    }

    return answer;
}

int main() {

    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"stanko", "ana", "mislav"};

    string ans = solution(participant, completion);

    cout << ans << '\n';

    return 0;
}