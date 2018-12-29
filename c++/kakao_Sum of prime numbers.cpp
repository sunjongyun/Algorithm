//
// Created by SUN on 2018-12-29.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10000001;

long long solution(int N) {
    long long answer = 0;

    vector<int> prime(N+1,0);

    for (int i=2; i<=N; i++){
        if (prime[i]==0){
            answer+=i;
            for (int k=i*2; k<=N; k+=i){
                prime[k]=1;
            }
        }
    }

    return answer;
}

int main() {
    long long ans = solution(7);

    cout << ans << '\n';

    return 0;
}