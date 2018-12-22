//
// Created by SUN on 2018-12-03.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> flip(string A) {
    int n = A.size();

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (A[i] == '0') {
            v[i] = 1;
        } else v[i] = -1;
    }

    int biggest = 0;
    int ans_left = 0;
    int ans_right = -1;
    int left = 0;
    int right = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + v[i] >= 0) {
            sum += v[i];
            right = i;
            if (left == -1) {
                left = i;
            }
        } else {
            sum = 0;
            left = -1;
            right = -1;
        }

        if (biggest < sum) {
            biggest = sum;
            ans_left = left;
            ans_right = right;
        }
    }

    if(biggest==0){
        return vector<int>();
    }

    return vector<int>() = {ans_left + 1, ans_right + 1};

}


int main() {
    string S = "010111";
    vector<int> ans = flip(S);

    //If return empty array [], print empty character.
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}