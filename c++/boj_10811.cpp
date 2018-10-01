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
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }

    while (m--) {
        int start;
        int end;
        cin >> start >> end;
        reverse(v.begin() + start - 1, v.begin() + end);
    }

    for (int x: v) {
        cout << x << ' ';
    }
    cout << '\n';


    return 0;
}