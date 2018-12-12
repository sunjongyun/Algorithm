//
// Created by SUN on 2018-12-13.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

vector<int> makeString(int m, int oneNum) {
    vector<int> ret;
    for (int i = 0; i < m - oneNum; i++) {
        ret.push_back(0);
    }
    for (int i = 0; i < oneNum; i++) {
        ret.push_back(1);
    }

    return ret;
}

int solution(int n, int m, vector<set<int>> sets) {

    int ret = 0;
    bool isFind = false;

    for (int i = 1; i <= m; i++) {
        auto input = makeString(m, i);
        set<int> s;

        do {
            s.clear();
            for (int inputIndex = 0; inputIndex < m; inputIndex++) {
                if (input[inputIndex] == 1) {
                    for (int x:sets[inputIndex]) {
                        s.insert(x);
                    }
                }
            }

            if (s.size() == n) {
                isFind = true;
                ret = i;
                break;
            }
        } while (next_permutation(input.begin(), input.end()));

        if (isFind) {
            break;
        }
    }

    return ret;

}

int main() {
    char buff[1024];
    char *pch;
    int n; // the number of element U
    int m; // the number of sets
    scanf("%d", &n);
    scanf("%d\n", &m);
    vector<set<int>> sets(m, set<int>());
    sets.resize(m);

    for (int i = 0; i < m; i++) {
        gets(buff);
        pch = strtok(buff, " ");
        while (pch != NULL) {
            sets[i].insert(atoi(pch));
            pch = strtok(NULL, " ");
        }
    }

    int ans = solution(n, m, sets);

    cout << ans << '\n';
}