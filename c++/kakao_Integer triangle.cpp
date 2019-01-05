//
// Created by SUN on 2019-01-06.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (1 <= j && j <= triangle[i].size() - 2) {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            } else if (j == 0) {
                triangle[i][j] += triangle[i - 1][j];
            } else if (j == triangle[i].size() - 1) {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
        }
    }

    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}

int main() {
    cout << solution({{7},
                      {10, 15},
                      {18, 16, 15},
                      {20, 25, 20, 19},
                      {24, 30, 27, 26, 24}}) << '\n';

    return 0;
}