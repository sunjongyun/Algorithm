//
// Created by mac on 2018. 10. 2..
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    while (n--) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;

    while (m--) {
        int search;
        scanf("%d", &search);
        auto p = equal_range(v.begin(), v.end(), search);
        if (p.first == p.second) {
            printf("%d ", 0);
        } else {
            printf("%d ", 1);
        }
    }


    return 0;
}