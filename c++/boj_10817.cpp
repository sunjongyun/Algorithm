//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    cout << (a + b + c) - min({a, b, c}) - max({a, b, c}) << '\n';


    return 0;
}
