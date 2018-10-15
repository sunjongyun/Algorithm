//
// Created by mac on 2018. 10. 15..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;

    vector<int> v;
    cin >> n >> m;

    int arr[10000];

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        arr[i] = sum;
        if (arr[i] == m) {
            ans++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((arr[j] - arr[i - 1]) == m) {
                ans++;
            }
        }
    }


    cout << ans << '\n';

    return 0;
}