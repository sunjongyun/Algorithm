//
// Created by SUN on 2018-12-10.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const long long mod = 4294967296; // pow(2,32)


void init(queue<int> &sign, queue<long long> &a) {
    while (!sign.empty()) {
        sign.pop();
    }

    while (!a.empty()) {
        a.pop();
    }

}


int main() {
    int n;
    cin >> n;

    queue<long long> a;
    queue<int> sign;


    while (n--) {
        int search, k;
        cin >> search >> k;

        init(sign, a);
        int ans = 0;

        int sum = 1984;
        int cnt = 1;
        long long prev = 1983;
        long long trans = 1984;
        a.push(prev);
        sign.push(trans);

        while (cnt <= k) {
            if (sum == search) {
                ans++;
                sum -= sign.front();
                sign.pop();
                a.pop();

            } else if (sum < search) {
                cnt++;
                prev = (prev * 214013 + 2531011) % mod;
                trans = prev % 10000 + 1;
                a.push(prev);
                sign.push(trans);
                sum += trans;
            } else if (sum > search) {
                sum -= sign.front();
                a.pop();
                sign.pop();
            }
        }

        cout << ans << '\n';


    }


    return 0;
}