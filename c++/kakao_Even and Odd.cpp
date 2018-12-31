//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>

using namespace std;

string solution(int num) {
    return num % 2 == 1 || num % 2 == -1 ? "Odd" : "Even";
}

int main() {

    cout << solution(-1) << '\n';

    return 0;
}