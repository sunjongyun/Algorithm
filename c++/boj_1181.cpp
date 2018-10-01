//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    while (n--) {
        string input;
        cin >> input;

        v.push_back(input);
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        if (a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    });

    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());

    for (string str:v) {
        cout << str << '\n';
    }


    return 0;
}