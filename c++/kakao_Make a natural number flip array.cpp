//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    while (n/10){
        answer.push_back(n%10);
        n/=10;
    }
    answer.push_back(n);

    return answer;
}

int main() {
    auto ans = solution(12345);
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}