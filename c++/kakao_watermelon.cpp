//
// Created by SUN on 2018-12-31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n / 2; i++) {
        answer += "수박";
    }
    if (n % 2) answer += "수";

    return answer;
}

int main() {
    cout << solution(4) << '\n';
    return 0;
}