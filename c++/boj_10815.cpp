//
// Created by mac on 2018. 9. 28..
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    set<int> card;

    while (n--) {
        int x;
        scanf("%d", &x);
        card.insert(x);
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        cout << card.count(x) << ' ';
    }

    return 0;
}