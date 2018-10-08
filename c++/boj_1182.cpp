//
// Created by SUN on 2018-10-07.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int dfs(int sum, int goal, int index) {
    if (index == v.size()) {
        if (sum == goal) {
            return 1;
        } else {
            return 0;
        }
    }

    int ans = 0;
    ans += dfs(sum, goal, index + 1);
    ans += dfs(sum + v[index], goal, index + 1);

    return ans;
}

int main() {
    int n;
    int s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int ans = 0;
    ans += dfs(0, s, 1);
    ans += dfs(v[0], s, 1);

    if (s == 0) { // 합이 0이고 공집합이면 안되니까 -1해준다.
        ans--;
    }

    cout << ans << '\n';

    return 0;
}