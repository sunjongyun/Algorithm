//
// Created by mac on 2018. 10. 22..
//

#include <iostream>

using namespace std;

int d[1000001];

int go(int n) {
    if (n==1){
        return 0;
    }

    if (d[n]>0) return d[n];

    d[n]=go(n-1)+1;
    if (n%2==0){
        if (d[n]>d[n/2]+1){
            d[n]=d[n/2]+1;
        }
    }
    if (n%3==0){
        if (d[n]>d[n/3]+1){
            d[n]=d[n/3]+1;
        }
    }

    return d[n];
}

int main() {
    int n;
    cin >> n;

    //init array
    for (int i = 0; i < 1000001; i++) {
        d[i] = 0;
    }
    int ans = go(n);

    cout << ans << '\n';

    return 0;
}