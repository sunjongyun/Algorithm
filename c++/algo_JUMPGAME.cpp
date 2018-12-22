//
// Created by SUN on 2018-12-23.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int visited[101][101]; // -1 :Not visited, 0:Not arrive, 1: Arrival is possible

int solve(int r, int c, int n, const vector<vector<int>> &map) {

    if (!(0 <= r && r < n && 0 <= c && c < n)) { // Out of range
        return 0;
    }

    if (r == n - 1 && c == n - 1) { // When you reach the destination
        return 1;
    }

    int &ret = visited[r][c];

    if (ret != -1) return ret;

    ret = 0;
    int jump = map[r][c];
    if (solve(r + jump, c, n, map) == 1) ret = 1;
    if (solve(r, c + jump, n, map) == 1) ret = 1;

    return ret;
}


int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
        memset(visited, -1, sizeof(visited)); // initialize all false

        int n;
        scanf("%d", &n);

        vector<vector<int>> map(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int ans = solve(0, 0, n, map);


        if (ans == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }


    }

    return 0;
}