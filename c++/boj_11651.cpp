//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int >> v;

    int index = 0;
    while (n--) {
        pair<int, int> p;
        scanf("%d %d", &p.second, &p.first);
        v.push_back(p);
        index++;
    }
    sort(v.begin(), v.end());

    for (pair<int, int> p : v) {
        printf("%d %d\n", p.second, p.first);
    }

    return 0;
}