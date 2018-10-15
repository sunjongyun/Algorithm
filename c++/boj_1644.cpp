//
// Created by mac on 2018. 10. 15..
//
#include <iostream>
#include <vector>

using namespace std;

bool prime[4000000];

void do_prime() {
    for (int i = 2; i < 4000000; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j < 4000000; j += i) {
                prime[j] = true;
            }
        }
    }

    for (int i = 0; i < 4000000; i++) {
        prime[i] = !prime[i];
    }
}

int main() {
    do_prime(); // 소수구하기 ( 에라토스테네스의 체 )

    int n;
    cin >> n;

    vector<int> v;

    // 소수만 골라서 vector에 넣는다.
    for (int i = 2; i < 4000000; ++i) {
        if (prime[i] == true) {
            v.push_back(i);
        }
    }

    int ans = 0;

    for (int i = 0; i < v.size(); ++i) {
        int sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum == n) {
                ans++;
            }
            if (sum > n) {
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}