//
// Created by SUN on 2018-10-03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int e = 15;
    int s = 28;
    int m = 19;
    int ans = 0;
    for (int i = 1;; i++) {
        int first = i % e != 0 ? i % e : e;
        int second = i % s != 0 ? i % s : s;
        int third = i % m != 0 ? i % m : m;

        if ((first == a) && (second == b) && (third == c)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';


    return 0;
}