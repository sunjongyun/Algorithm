//
// Created by SUN on 2019-01-03.
//

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();
    int prime[3001];
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 3000; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j <= 3000; j += i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // i,j,k가 서로 다를 때
                if (i != j && j != k && i != k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (prime[sum] == 0) {
                        answer++;
                    }
                }
            }
        }
    }

    return answer / 6; // 3개의 숫자를 선택 했을때, 중복된 방법의 수가 6개나 된다.
}

int main() {
    cout << solution(vector<int>{1, 2, 7, 6, 4}) << '\n';
    return 0;
}