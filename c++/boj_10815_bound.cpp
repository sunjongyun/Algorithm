//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <algorithm>
#include <vector>

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
        int u = upper_bound(v.begin(), v.end(), search) - v.begin();
        int l = lower_bound(v.begin(), v.end(), search) - v.begin();
        if (u == l) {
            printf("%d ", 0);
        } else {
            printf("%d ", 1);
        }
    }


    return 0;
}
