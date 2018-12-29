//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();

    vector<int> answer(n);

    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty()) {
            while (!st.empty() && st.top().first > prices[i]) {
                auto a = st.top();
                answer[a.second] = i - a.second;
                st.pop();
            }
        }
        st.push({prices[i], i});

    }

    while (!st.empty()) {
        auto a = st.top();
        st.pop();
        answer[a.second] = n - 1 - a.second;
    }

    return answer;
}

int main() {
    vector<int> prices = {498, 501, 470, 489};

    vector<int> ans = solution(prices);

    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}