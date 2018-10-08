//
// Created by mac on 2018. 10. 8..
//

#include <iostream>

using namespace std;

bool map[14][14];
int n;
bool straight_down[29];
bool left_down[29];
bool right_down[29];

bool check(int row, int col) {

    if (straight_down[col]) {
        return false;
    }
    if (right_down[row + col]) {
        return false;
    }
    if (left_down[row - col + (n - 1)]) {
        return false;
    }

    return true;
}

int cal(int row) {

    if (row == n) {
        return 1;
    }

    int ans = 0;
    for (int col = 0; col < n; col++) {
        map[row][col] = true;

        if (check(row, col)) {
            straight_down[col] = true;
            right_down[row + col] = true;
            left_down[row - col + (n - 1)] = true;
            ans += cal(row + 1);
            straight_down[col] = false;
            right_down[row + col] = false;
            left_down[row - col + (n - 1)] = false;
        }
        map[row][col] = false;

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