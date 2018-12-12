//
// Created by SUN on 2018-12-12.
//

#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 12345678;

int dfs(int n, int m, int cur, int ans, vector<set<int>> v, set<int> make) {

    int ret = 0;
    // 모든 set에 원소를 채웠을 때
    if (make.size() == n) {
        return ans;
    }

    if (cur == m) {
        return INF;
    }

    //포함 안하는 것
    int ret1 = dfs(n, m, cur + 1, ans, v, make);

    //포함 하는 것
    auto it = v[cur];
    for (int x:it) {
        make.insert(x);
    }
    int ret2 = dfs(n, m, cur + 1, ans + 1, v, make);

    ret = ret1 < ret2 ? ret1 : ret2;

    return ret;
}


/*
 * n : the number of element U
 * m : the number of sets
 * v : sets
 */
int solution(int n, int m, vector<set<int>> v) {
    int ans = 0;

    set<int> make;
    ans = dfs(n, m, 0, 0, v, make);

    return ans;
}

int main() {
    int n = 10; // the number of element U
    int m = 3; // the number of sets

    vector<set<int>> sets(m, set<int>());
    sets[0] = {1, 2, 3, 4, 5, 6};
    sets[1] = {1, 4, 7, 8};
    sets[2] = {2, 3, 5, 6, 9, 10};


    int ans = solution(n, m, sets);

    cout << ans << '\n';


}