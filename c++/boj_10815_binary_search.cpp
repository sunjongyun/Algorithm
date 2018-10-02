//
// Created by mac on 2018. 10. 2..
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
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;
    while (m--) {
        int search_num;
        scanf("%d", &search_num);
        printf("%d ", binary_search(v.begin(), v.end(), search_num));
    }


    return 0;
}