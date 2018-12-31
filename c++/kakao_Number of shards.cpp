//
// Created by SUN on 2019-01-01.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string str = to_string(x);
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += (str[i] - '0');
    }

    return x % sum == 0;
}

int main() {
    cout << solution(13) << '\n';
    return 0;
}