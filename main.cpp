#include <iostream>

using namespace std;

int get_gcd (int u, int v){

    if (u<v){ // u가 v보다 크다면
        int tmp=u;
        u=v;
        v=tmp;
    }

    if (v==0){
        return u;
    }

    int answer =get_gcd(u-v,v);


    return answer;
}

int main() {

    int answer= get_gcd(280, 30); // ans is 10 what I look forward;

    cout << answer << endl;

    return 0;
}