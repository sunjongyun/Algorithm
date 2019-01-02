//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;

    bitset<30> bitset1(n);
    int cur = n + 1;

    while (1) {
        bitset<30> bitset2(cur);

        if (bitset1.count() == bitset2.count()) {
            answer = cur;
            break;
        }
        cur++;
    }
    return answer;
}


int main() {

    cout << solution(15) << '\n';

    return 0;
}