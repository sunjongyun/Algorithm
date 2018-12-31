//
// Created by SUN on 2019-01-01.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    for (int i = 0; i < phone_number.size() - 4; i++) {
        phone_number[i] = '*';
    }
    return phone_number;
}

int main() {
    cout << solution("027778888") << '\n';

    return 0;
}