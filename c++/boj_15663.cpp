//
// Created by SUN on 2018-12-24.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void makeOrder(int n, int m, vector<int> &order) {
    for (int i = 0; i < n - m; i++) {
        order.push_back(0);
    }
    for (int i = 0; i < m; i++) {
        order.push_back(i + 1);
    }
}

int main() {


    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> order;
    makeOrder(n, m, order);

    set<vector<int>> ans;

    do {
        vector<int> tmp;
        for (int val = 1; val <= m; val++) {
            auto it = find(order.begin(), order.end(), val);
            int index = it - order.begin();
            tmp.push_back(v[index]);
        }

        ans.insert(tmp);
    } while (next_permutation(order.begin(), order.end()));

    for (auto x : ans) {
        for (int i = 0; i < m; i++) {
            cout << x[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}