//
// Created by SUN on 2018-12-31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int x: arr) answer+=x;
    return answer/arr.size();
}

int main() {
    cout << solution(vector<int>{5,5}) << endl;
    return 0;
}