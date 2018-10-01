//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int x : v) {
        cout << x << '\n';
    }


    return 0;
}