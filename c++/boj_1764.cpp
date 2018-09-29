//
// Created by mac on 2018. 9. 29..
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> kim;

    int n;
    int m;

    cin >> n >> m;
    while (n--) {
        string input;
        cin >> input;
        kim[input] += 1;
    }

    while (m--) {
        string input;
        cin >> input;
        kim[input] += 1;
    }

    int ans = 0;
    for (auto p: kim) {
        if (p.second == 2) {
            ans++;
        }
    }
    printf("%d\n", ans);

    for (auto p: kim) {
        if (p.second == 2) {
            cout << p.first << '\n';
        }
    }


    return 0;
}