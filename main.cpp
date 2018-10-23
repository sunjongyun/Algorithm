#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int seek;

    vector<int> a;

    cin >> n >> seek;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int right = 0;
    int left = 0;
    int sum = a[0];
    int ans = 987654321;
    while (right != n && left != n) {
        int size = 0;
        if (sum == seek) {
            size = right - left + 1;
            if (ans > size) ans = size;
            right++;
            if (right == n) break;
            sum += a[right];
        } else if (sum > seek) {
            size = right - left + 1;
            if (ans > size)ans = size;
            sum -= a[left];
            left++;
        } else if (sum < seek) {
            right++;
            if (right == n) break;
            sum += a[right];
        }
    }

    if (ans == 987654321) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}