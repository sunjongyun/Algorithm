//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v;
    while (n--) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int max = -987654321;
    do {
        int total = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            total += abs(v[i] - v[i + 1]);
        }

        if (max < total) {
            max = total;
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << max << '\n';

    return 0;
}