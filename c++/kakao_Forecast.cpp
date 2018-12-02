//
// Created by SUN on 2018-12-02.
//

#include <iostream>

using namespace std;

int dfs(int a, int b) {
    int big=max(a,b); //big
    int small=min(a,b); //small

    if ((big - small) == 1 && small % 2 == 1) {
        return 1;
    }

    int ret = dfs((a + 1) / 2, (b + 1) / 2) + 1;


    return ret;
}

int solution(int n, int a, int b) {
    int answer;


    answer=dfs(a, b);

    return answer;
}


int main() {
    int ans = solution(100, 1, 100);

    cout << ans << '\n';

    return 0;
}