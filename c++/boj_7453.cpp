//
// Created by mac on 2018. 10. 17..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> first(n * n);
    vector<int> second(n * n);

    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            first[index] = a[i] + b[j];
            second[index] = c[i] + d[j];
            index++;
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());

    n = n * n;

    long long ans = 0;
    int i = 0;
    int j = 0;

    while (i != n && j != n) {
        if ((first[i] + second[j]) == 0) {
            long long c1 = 1;
            long long c2 = 1;

            i++;
            while (i != n) {
                if (first[i] == first[i - 1]) {
                    c1++;
                    i++;
                } else {
                    break;
                }
            }

            j++;
            while (j != n) {
                if (second[j] == second[j - 1]) {
                    c2++;
                    j++;
                } else {
                    break;
                }
            }

            ans += (c1 * c2);
        } else if ((first[i] + second[j]) > 0) {
            j++;
        } else if ((first[i] + second[j]) < 0) {
            i++;
        }
    }

    cout << ans << '\n';

    return 0;
}