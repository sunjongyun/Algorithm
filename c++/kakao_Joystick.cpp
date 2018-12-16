//
// Created by SUN on 2018-12-16.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> getOrder(int n) {
    vector<vector<char>> ret;

    vector<char> v; // L: left, R:right
    for (int lnum = 0; lnum < n - 1; lnum++) {
        v.clear();
        int rnum = n - 1 - lnum;
        for (int i = 1; i <= lnum; i++) {
            v.push_back('L');
        }
        for (int i = 1; i <= rnum; i++) {
            v.push_back('R');
        }
        ret.push_back(v);
    }

    for (int rnum = 0; rnum < n - 1; rnum++) {
        v.clear();
        int lnum = n - 1 - rnum;
        for (int i = 1; i <= rnum; i++) {
            v.push_back('R');
        }
        for (int i = 1; i <= lnum; i++) {
            v.push_back('L');
        }

        ret.push_back(v);
    }

    return ret;
}

string getString(int n) {
    string init = "";
    for (int i = 0; i < n; i++) {
        init += 'A';
    }

    return init;
}

bool isSame(string init, string name) {
    bool ret = false;
    if (init == name) {
        ret = true;
    }

    return ret;
}

int solution(string name) {
    int answer = 987654321;
    int n = name.size();

    auto orders = getOrder(n);

    for (int i = 0; i < orders.size(); i++) {
        vector<char> nowOrder = orders[i];
        int cnt = 0;
        int cur = 0; //Current Index
        string init = getString(n); // ex: Set to AAAAA

        //first Character
        cnt += min(name[0] - init[0], 26 - name[0] + init[0]);
        init[0] = name[0];

        if (isSame(init, name)) {
            if (cnt < answer) {
                answer = cnt;
            }
            continue;
        }

        for (int k = 0; k < n - 1; k++) {
            cnt++;

            if (nowOrder[k] == 'L') {
                cur--;
                cur = cur == -1 ? n - 1 : cur;

                cnt += min(name[cur] - init[cur], 26 - name[cur] + init[cur]);
                init[cur] = name[cur];
            } else if (nowOrder[k] == 'R') {
                cur++;
                cur = cur == n ? 0 : cur;

                cnt += min(name[cur] - init[cur], 26 - name[cur] + init[cur]);
                init[cur] = name[cur];
            }

            if (isSame(init, name)) {
                if (cnt < answer) {
                    answer = cnt;
                }
                break;
            }
        }
    }

    return answer;
}

int main() {
    string name = "ABAAAAAAAAABB";

    int ans = solution(name);

    cout << ans << '\n';

    return 0;
}