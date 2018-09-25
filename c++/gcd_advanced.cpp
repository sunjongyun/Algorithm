//
// Created by SUN on 2018-09-26.
//

#include <iostream>

using namespace std;

int gcd(int u, int v){
    while (v!=0){
        u=u%v;
        int tmp=u;
        u=v;
        v=tmp;
    }

    return u;
}

int main(){

    int ans=gcd(30, 280);

    cout<< ans << endl;

    return 0;
}