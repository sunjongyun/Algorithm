//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), [](const int &u, const int &v) {
        string a = (to_string(u) + to_string(v));
        string b = (to_string(v) + to_string(u));

        return a > b;
    });

    for (int x:numbers) {
        answer += to_string(x);
    }
    if (answer[0] == '0') return string("0");
    return answer;
}

int main() {
    cout << solution(vector<int>{0, 0, 0, 0}) << '\n';

    return 0;
}