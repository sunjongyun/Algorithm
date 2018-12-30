//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer += ("김서방은 " + to_string(index) + "에 있다");

    return answer;
}

int main() {
    cout << solution(vector<string>{"Jane", "Kim"}) << '\n';

    return 0;
}