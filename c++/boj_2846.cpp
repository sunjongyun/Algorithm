//
// Created by SUN on 2018-12-18.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> v) {
    int answer = 0;
    int memo = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i - 1] >= v[i]) {
            int gap = v[i - 1] - memo;
            answer = answer < gap ? gap : answer;
            memo = v[i];
        }
    }

    int gap = v[n - 1] - memo;
    answer = answer < gap ? gap : answer;

    return answer;
}


int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = solution(n, v);

    cout << ans << '\n';

    return 0;
}