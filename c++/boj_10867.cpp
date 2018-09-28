//
// Created by mac on 2018. 9. 28..
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;

    while (n--) {
        int input;
        cin >> input;

        s.insert(input);

    }

    for (int x: s) {
        cout << x << ' ';
    }
    cout << '\n';

}