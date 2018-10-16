//
// Created by mac on 2018. 10. 16..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    m = n / 2;
    n = n - m;

    vector<int> first(1 << n);
    vector<int> second(1 << m);

    // Make first subset
    for (int i = 0; i < (1 << n); i++) {
        for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
                first[i] += a[k];
            }
        }
    }

    // Make second subset
    for (int i = 0; i < (1 << m); i++) {
        for (int k = 0; k < m; k++) {
            if (i & (1 << k)) {
                second[i] += a[n + k];
            }
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());
    n = (1 << n);
    m = (1 << m);
    int i = 0;
    int j = 0;
    long long ans = 0;

    while (i < n && j < m) {

        if (first[i] + second[j] == s) {
            long c1 = 1;
            long c2 = 1;

            i++;
            while (i < n) {
                if (first[i] == first[i - 1]) {
                    i++;
                    c1++;
                } else {
                    break;
                }
            }

            j++;
            while (j < m) {
                if (second[j] == second[j - 1]) {
                    j++;
                    c2++;
                } else {
                    break;
                }
            }

            ans += c1 * c2;

        } else if (first[i] + second[j] < s) {
            i++;
            if (i == n) {
                break;
            }
        } else if (first[i] + second[j] > s) {
            j++;
            if (j == m) {
                break;
            }
        }
    }

    if (s == 0) ans -= 1;

    cout << ans << '\n';
    return 0;
}