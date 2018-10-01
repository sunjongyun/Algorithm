//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    while (m--) {
        int tmp1;
        int tmp2;
        cin >> tmp1 >> tmp2;
        auto it = a.begin();
        swap(*(it + tmp1 - 1), *(it + tmp2 - 1));

    }

    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}