//
// Created by mac on 2018. 12. 22..
//

#include <iostream>
#include <string>

using namespace std;

bool solution(string search, string des) {
    bool ans = true;

    string front;
    string mid;
    string back;


    int pos = search.find('*', 1);

    front = search.substr(0, pos);
    mid = "*";
    back = search.substr(pos + 1);

    for (int i = 0; i < front.size(); i++) {
        if (des[i] != front[i]) {
            ans = false;
            return false;
        }
    }

    for (int i = 0; i < back.size(); i++) {
        if (des[des.size() - back.size() + i] != back[i]) {
            ans = false;
            return false;
        }
    }

    if (front.size() + back.size() > des.size()) {
        ans = false;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    string search;
    cin >> search;

    while (n--) {
        string des;
        cin >> des;

        bool ans = solution(search, des);

        if (ans) {
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }


    return 0;
}