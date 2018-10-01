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

    vector<int> v(n, 0);

    while (m--) {
        int start;
        int end;
        int value;
        cin >> start >> end >> value;
        fill(v.begin() + start - 1, v.begin() + end, value);
    }


    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';


    return 0;
}