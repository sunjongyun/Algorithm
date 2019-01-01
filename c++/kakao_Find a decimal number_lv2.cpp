//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 10000000;

int solution(string numbers) {
    set<int> answer;
    vector<int> prime(MAX);
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j <= MAX; j += i) {
                prime[j] = 1;
            }
        }
    }

    int n = numbers.size();
    for (int length = 1; length <= n; length++) {
        string s = "";
        for (int i = 0; i < n - length; i++) {
            s += "0";
        }
        for (int i = 1; i <= length; i++) {
            s += to_string(i);
        }
        do {
            string maked = "";
            for (int i = 1; i <= length; i++) {
                auto it = find(s.begin(), s.end(), i + '0');
                maked += numbers[it - s.begin()];
            }
            int num = stoi(maked);
            if (!prime[num]) {
                answer.insert(num);
            }
        } while (next_permutation(s.begin(), s.end()));
    }


    return answer.size();
}

int main() {
    cout << solution("9876542") << '\n';

    return 0;
}