//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <vector>

using namespace std;

int getValue(vector<int> A, vector<int> B) {
    int ret = 0;

    for (int i = 0; i < A.size(); i++) {
        ret += A[i] * B[i];
    }

    return ret;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // arr1 이 A*B 행렬이고, arr2가 B*C 행렬이면
    // answer는 A*C행렬이다. 이 과정을 처음에 A*C행렬의 크기로 만들었다.
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));

    int n = answer.size();
    int m = answer[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> trans; // arr2에서 세로로 한줄
            for (auto x: arr2) {
                trans.push_back(x[j]);
            }
            answer[i][j] = getValue(arr1[i], trans);
        }
    }

    return answer;
}

int main() {
    auto ans = solution(vector<vector<int>>{{2, 3, 2},
                                            {4, 2, 4},
                                            {3, 1, 4}}, vector<vector<int>>{{5, 4, 3},
                                                                            {2, 4, 1},
                                                                            {3, 1, 1}});

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}