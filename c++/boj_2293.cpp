//
// Created by SUN on 2018-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> d(100001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - a[i] >= 0) {
                d[j] += d[j - a[i]];
            }
        }
    }

    cout << d[k] << '\n';


    return 0;
}