//
// Created by mac on 2018. 10. 19..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> a;

    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(7);
    a.push_back(9);

    for (int i = 10; i < 100; i++) {
        a.push_back(a[i - 1] + a[i - 5]);
    }

    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        cout << a[num - 1] << '\n';
    }


    return 0;
}