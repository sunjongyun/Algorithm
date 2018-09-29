//
// Created by mac on 2018. 9. 29..
//

#include <iostream>
#include <map>

using namespace std;

int main() {

    map<string, pair<int, int>> reg = {{"black",  make_pair(0, 1)},
                                       {"brown",  make_pair(1, 10)},
                                       {"red",    make_pair(2, 100)},
                                       {"orange", make_pair(3, 1000)},
                                       {"yellow", make_pair(4, 10000)},
                                       {"green",  make_pair(5, 100000)},
                                       {"blue",   make_pair(6, 1000000)},
                                       {"violet", make_pair(7, 10000000)},
                                       {"grey",   make_pair(8, 100000000)},
                                       {"white",  make_pair(9, 1000000000)}};


    string first;
    string second;
    string third;

    cin >> first >> second >> third;

    long num1;
    long num2;
    long num3;

    num1 = reg[first].first * 10;
    num2 = reg[second].first;
    num3 = reg[third].second;

    long ans = (num1 + num2) * num3;
    cout << ans;
    return 0;
}
