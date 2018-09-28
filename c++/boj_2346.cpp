//
// Created by mac on 2018. 9. 27..
//

#include <iostream>
#include <list>

using namespace std;

int main() {

    int n;
    cin >> n;
    list<pair<int, int>> l;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        l.push_back({x, i});
    }

    auto it = l.begin();
    for (int j = 0; j < n - 1; ++j) {
        cout << it->second << ' ';
        int step = it->first;
        if (step > 0) {
            auto tmp = it;
            tmp++;
            if (tmp == l.end()) {
                tmp = l.begin();

            }
            l.erase(it);
            it = tmp;
            for (int i = 1; i < step; ++i) {
                it++;
                if (it == l.end()) {
                    it = l.begin();

                }
            }

        } else if (step < 0) {
            step = -step;
            auto tmp = it;
            if (tmp == l.begin()) {
                tmp = l.end();
            }
            tmp--;
            l.erase(it);
            it = tmp;
            for (int i = 1; i < step; ++i) {
                if (it == l.begin()) {
                    it = l.end();
                }
                it--;
            }
        }
    }

    cout << l.begin()->second << '\n';


    return 0;
}