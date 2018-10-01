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

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }


    while (m--) {
        int start;
        int mid;
        int end;
        cin >> start >> end >> mid;
        rotate(v.begin() + start - 1, v.begin() + mid - 1, v.begin() + end);
    }

    for (int x : v) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}