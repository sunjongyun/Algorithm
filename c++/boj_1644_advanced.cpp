//
// Created by SUN on 2018-10-16.
//

#include <iostream>
#include <vector>
#include <stdexcept>

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
    do_prime();
    int seek;
    cin >> seek;

    vector<int> v;
    for (int i = 2; i < 4000000; i++) {
        if (prime[i] == true) {
            v.push_back(i);
        }
    }

    int right = 0;
    int left = 0;
    int sum = v[0];
    int ans = 0;


    int n = v.size();
    while (right != n && left != n) {
        if (sum == seek) {
            ans++;
            right++;
            if (right == n) break;
            sum += v[right];
        } else if (sum > seek) {
            sum -= v[left];
            left++;
        } else if (sum < seek) {
            right++;
            if (right == n) break;
            sum += v[right];
        }

    }

    cout << ans << '\n';


    return 0;
}