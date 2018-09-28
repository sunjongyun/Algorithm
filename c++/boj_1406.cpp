//
// Created by mac on 2018. 9. 28..
//

#include <iostream>
#include <list>

using namespace std;

int main() {
    list<char> l;

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        l.push_back(str[i]);
    }

    int n;
    cin >> n;

    auto it = l.end();
    while (n--) {
        string input;
        cin >> input;
        if (input == "L") {
            if (it != l.begin()) {
                it--;
            }
        } else if (input == "D") {
            if (it != l.end()) {
                it++;
            }
        } else if (input == "B") {
            if (it != l.begin()) {
                auto tmp = it;
                tmp--;
                l.erase(tmp);
            }
        } else if (input == "P") {
            cin >> input;
            l.insert(it, input[0]);
        }
    }

    for (char c: l) {
        cout << c;
    }

    return 0;
}
