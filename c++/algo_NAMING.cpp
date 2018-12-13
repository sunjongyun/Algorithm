//
// Created by SUN on 2018-12-13.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPartialMatch(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);
    //KMP로 자기 자신을 찾는다.
    //N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니까 안됨!
    int begin = 1, matched = 0;
    //비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> solution(string plus) {
    vector<int> ret;
    ret.push_back(plus.size());
    int i = plus.size();
    auto pi = getPartialMatch(plus);

    while (pi[i - 1] != 0) {

        ret.push_back(pi[i - 1]);
        i = pi[i - 1];


    }

    return ret;
}

int main() {

    string father, mother;
    cin >> father >> mother;
    string plus = father + mother;

    auto ans = solution(plus);

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}