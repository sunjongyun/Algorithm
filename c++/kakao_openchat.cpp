//
// Created by SUN on 2018-12-03.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;

    char c[100];
    for (auto str : record) {
        strcpy(c, str.c_str());

        char *token = strtok(c, " ");
        if (string(token) != "Leave") {
            char *key = strtok(NULL, " ");
            char *value = strtok(NULL, " ");
            m[key] = value;
        }
    }

    for (auto str : record) {
        strcpy(c, str.c_str());

        char *token = strtok(c, " ");
        char *key = strtok(NULL, " ");
        string cmd = string(token);
        string input;

        if (cmd == "Enter") {
            input = m[key] + "님이 들어왔습니다.";
        } else if (cmd == "Leave") {
            input = m[key] + "님이 나갔습니다.";
        } else if (cmd == "Change") {
            continue;
        }

        answer.push_back(input);
    }


    return answer;
}

int main() {

    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");

    vector<string> ans = solution(record);

    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}

//["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]