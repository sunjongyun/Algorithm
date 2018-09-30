//
// Created by mac on 2018. 9. 30..
//

#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2;
    string s3;
    string s4;

    cin >> s1 >> s2 >> s3 >> s4;

    string sum1 = s1 + s2;
    string sum2 = s3 + s4;

    long long ans = stoll(sum1) + stoll(sum2);

    cout << ans << '\n';

    return 0;
}