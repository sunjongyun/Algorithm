//
// Created by mac on 2018. 10. 8..
//

#include <iostream>

using namespace std;

bool map[14][14];
int n;

bool check(int row, int col) {

    int tmp = 1;
    for (int nextRow = row - 1; nextRow >= 0; nextRow--) {
        // straight down
        if (map[nextRow][col]) {
            return false;
        }


        // left down
        int nextCol = col - tmp;
        if (nextCol >= 0) {
            if (map[nextRow][nextCol]) {
                return false;
            }
        }

        // right down
        nextCol = col + tmp;
        if (nextCol < n) {
            if (map[nextRow][nextCol]) {
                return false;
            }
        }
        tmp++;
    }

    return true;
}

int cal(int row) {

    if (row == n) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        map[row][i] = true;
        if (check(row, i)) {
            ans += cal(row + 1);
        }
        map[row][i] = false;
    }

    return ans;
}

int main() {
    cin >> n;

    int ans = 0;
    ans = cal(0);


    cout << ans << '\n';
    return 0;
}