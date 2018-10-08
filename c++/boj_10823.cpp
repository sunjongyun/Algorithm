//
// Created by mac on 2018. 9. 30..
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s = "";
    string seg = "";
    int ans = 0;

    while (getline(cin, seg)) {
        s += seg;
    }

    istringstream sin(s);

    while (getline(sin, s, ',')) {
        ans += stoi(s);
    }

    cout << ans << '\n';


    return 0;
}

