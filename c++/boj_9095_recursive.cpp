//
// Created by SUN on 2018-10-06.
//

#include <iostream>

using namespace std;

int go(int goal, int sum) {

    //sum>최종값 이면 return 0
    //sum==최종값이랑 같으면 return 1
    if (sum > goal) {
        return 0;
    }
    if (sum == goal) {
        return 1;
    }

    int ans = 0;
    //go(1)
    //go(2)
    //go(3)
    for (int i = 1; i <= 3; i++) {
        ans += go(goal, sum + i);
    }

    return ans;

}

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {

        int n;
        cin >> n;

        int res = go(n, 0);


        cout << res << '\n';
    }

    return 0;
}