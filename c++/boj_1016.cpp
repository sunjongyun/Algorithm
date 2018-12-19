//
// Created by SUN on 2018-12-20.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const long long MAX = 1000000;

void makePrime(bool primes[]) {
    primes[0] = primes[1] = false;
    for (long long i = 2; i <= MAX; i++) {
        if (primes[i]) {
            long long j = 2;
            while ((i * j) <= MAX) {
                primes[i * j] = false;
                j++;
            }
        }
    }
}

long long solution(long long start, long long end) {
    long long answer = 0;
    bool primes[1000001];
    memset(primes, true, sizeof(primes));

    makePrime(primes);

    vector<long long> pv; // prime Vector
    for (long long i = 2; i <= MAX; i++) {
        if (primes[i]) {
            pv.push_back(i * i);
        }
    }


    vector<bool> rv(end - start + 1, true); //result Vector
    for (long long i = 0; i < pv.size(); i++) {
        long long prime = pv[i];
        long long under = start - (start % prime);
        if (under == start) {
            under -= prime;
        }
        while ((under + prime) <= end) {
            under += prime;
            rv[under - start] = false;
        }
    }

    for (int i = 0; i < end - start + 1; i++) {
        if (rv[i] == true) {
            answer++;
        }
    }


    return answer;
}


int main() {
    long long start, end;
    cin >> start >> end;

    long long ans = solution(start, end);

    cout << ans << '\n';

    return 0;
}