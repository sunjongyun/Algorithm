//
// Created by SUN on 2019-01-05.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/* Union Find 알고리즘 사용( kruskal의 전신 )
 * root[i] : i 노드의 부모노드가 적혀있음. root[i]를 거슬로 올라가면 root노드에 정착할 수 있다.
 * root는 root[i]와 i가 같은게 특징.
 * */
int findRoot(int x, int *root) {
    if (root[x] == x) {
        return x;
    } else {
        return findRoot(root[x], root);
    }
}

void combine(int x, int y, int *root) {
    x = findRoot(x, root);
    y = findRoot(y, root);

    root[x] = y;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](const vector<int> &u, const vector<int> &v) {
        return u[2] < v[2];
    });

    int root[n];
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }


    int num = 0;
    for (auto x: costs) {
        int a = findRoot(x[0], root);
        int b = findRoot(x[1], root);

        if (a != b) {
            combine(x[0], x[1], root);
            answer += x[2];
        }

        if (num == n - 1) {
            break;
        }
    }

    return answer;
}

int main() {
    cout << solution(4, vector<vector<int>>{{0, 1, 1},
                                            {0, 2, 2},
                                            {1, 2, 5},
                                            {1, 3, 1},
                                            {2, 3, 8}}) << '\n';
    return 0;
}