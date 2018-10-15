//
// Created by mac on 2018. 10. 15..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int seek;

    cin >> n >> seek;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int left = 0;
    int right = 0;
    int sum = v[0];
    int ans = 987654321; // First, put a very large value

    // If seek >=sum, Enter the minimum length to ans.
    while (right != n && left != n) {
        if (sum == seek) {
            int size = right - left + 1;
            if (ans > size) {
                ans = size;
            }
            right++;
            sum += v[right];
        } else if (sum > seek) {
            int size = right - left + 1;
            if (ans > size) {
                ans = size;
            }
            sum -= v[left];
            left++;
        } else if (sum < seek) {
            right++;
            sum += v[right];
        }
    }

    if (ans == 987654321) { // If the sum of subsets is not found
        cout << 0 << '\n';
    } else { // found!!
        cout << ans << '\n';
    }

    return 0;
}