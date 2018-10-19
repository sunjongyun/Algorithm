//
// Created by mac on 2018. 10. 18..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[2];

    a[0] = 0;
    a[1] = 1;


    for (int i = 2; i <= n; i++) {
        long long tmp[2];
        tmp[0] = a[0] + a[1];
        tmp[1] = a[0];
        a[0] = tmp[0];
        a[1] = tmp[1];
    }

    cout << a[0] + a[1] << '\n';


    return 0;
}