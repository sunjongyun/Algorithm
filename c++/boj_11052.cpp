//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> p(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    int d[1001];

    for (int i = 1; i <= n; i++) {
        int max = p[i];
        for (int j = 1; j < n; j++) {
            if ((i - j) > 0) {
                if (max < (p[j] + d[i - j])) {
                    max = p[j] + d[i - j];
                }
            } else {
                break;
            }
        }
        d[i] = max;
    }

    cout << d[n] << '\n';

    return 0;
}