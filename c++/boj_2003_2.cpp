//
// Created by mac on 2018. 10. 15..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int seek;

    vector<int> v;
    cin >> n >> seek;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int left = 0;
    int right = 0;

    int ans = 0;
    int sum = v[0];
    while (true) {
        // 값을 찾은 경우
        if (sum == seek) {
            ans++;
            right++;
            if (right == n) {
                break;
            }
            sum += v[right];
        } else if (sum > seek) {
            sum -= v[left];
            left++;
            if (left == n) {
                break;
            }
        } else if (sum < seek) {
            right++;
            if (right == n) {
                break;
            }
            sum += v[right];
        }

    }

    cout << ans << '\n';

    return 0;
}