//
// Created by SUN on 2019-01-06.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    for (int i = 0; i < routes.size(); i++) {
        int &u = routes[i][0];
        int &v = routes[i][1];
        if (u > v) swap(u, v);
    }

    sort(routes.begin(), routes.end(), [](const vector<int> &u, const vector<int> &v) {
        return u[1] < v[1];
    });

    int lastestEnd = -123456789;
    for (auto x: routes) {
        if (lastestEnd >= x[0]) {
            continue;
        } else {
            lastestEnd = x[1];
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<vector<int>>{{-2, -3},
                                         {-4, 4},
                                         {2,  1},
                                         {4,  2}}) << '\n';

    return 0;
}