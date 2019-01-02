//
// Created by SUN on 2019-01-03.
//

#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;

    while (n != 0) {
        if (n % 2) {
            n -= 1;
            ans++;
        } else {
            n /= 2;
        }
    }

    return ans;
}

int main() {
    cout << solution(5000) << '\n';

    return 0;
}