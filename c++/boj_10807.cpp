//
// Created by mac on 2018. 10. 1..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> v;
    while (n--) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int search_num;
    cin >> search_num;
    int ans = count(v.begin(), v.end(), search_num);
    cout << ans << '\n';
    return 0;
}