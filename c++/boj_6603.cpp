//
// Created by mac on 2018. 10. 4..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<int> v;
        for (int i = 0; i < 6; ++i) {
            v.push_back(0);
        }
        for (int i = 0; i < n - 6; i++) {
            v.push_back(1);
        }


        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        do {
            for (int i = 0; i < (int) v.size(); ++i) {
                if (v[i] == 0) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");

        } while (next_permutation(v.begin(), v.end()));

        // 빈 줄을 출력
        cout << '\n';
    }

    return 0;
}