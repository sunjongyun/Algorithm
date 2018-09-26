//
// Created by SUN on 2018-09-26.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {

    int a = 7;
    int b = 3;

    vector<function<int(int, int)>> d;

    d.push_back([](int a, int b) {
        return a + b;
    });
    d.push_back([](int a, int b) {
        return a - b;
    });
    d.push_back([](int a, int b) {
        return a * b;
    });
    d.push_back([](int a, int b) {
        return a / b;
    });
    d.push_back([](int a, int b) {
        return a % b;
    });

    for (auto &f : d) {
        cout << f(a, b) << endl;
    }

    return 0;
}