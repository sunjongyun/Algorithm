//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string str=to_string(n);
    sort(str.begin(),str.end(),greater<char>());
    answer=stoll(str);

    return answer;
}

int main()
{
    cout << solution(9876543210) << '\n';

    return 0;
}