//
// Created by SUN on 2018-12-31.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    int a = __gcd(n, m);
    return vector<int>{a, n * m / a};
}

int main() {
    auto ans = solution(2, 5);
    for (int x:ans) {
        cout << x << ' ';
    }
    cout << '\n';
}