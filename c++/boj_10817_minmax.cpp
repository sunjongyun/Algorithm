//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    auto p = minmax({a, b, c});
    cout << (a + b + c) - p.first - p.second << '\n';

    return 0;
}