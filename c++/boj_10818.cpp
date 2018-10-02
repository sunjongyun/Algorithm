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

    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());

    cout << *min_it << ' ' << *max_it << '\n';


    return 0;
}