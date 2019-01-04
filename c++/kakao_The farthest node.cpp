//
// Created by SUN on 2019-01-05.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    map<int, vector<int>> nodes; // edge에서 연결되어 있는 노드들
    // map을 사용하는 이유는 edge들을 모두 선회하면서 연결노드를 찾는것보다 map을 이용해서
    // 찾는 편이 훨씬 빠르기 때문
    for (int i = 0; i < edge.size(); i++) {
        int first = edge[i][0];
        int second = edge[i][1];
        nodes[first].push_back(second);
        nodes[second].push_back(first);
    }

    map<int, int> dist; // 1과 떨어져 있는 거리
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int biggest = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        biggest = biggest < dist[now] ? dist[now] : biggest;

        for (int x: nodes[now]) { // now와 연결되어있는 모든 노드들을 검사
            if (dist.count(x) == 0) { // 아직 방문하지 않았다면
                q.push(x);
                dist[x] = dist[now] + 1;
            }
        }
    }

    for (auto x:dist) {
        if (x.second == biggest) answer++;
    }
    return answer;
}

int main() {
    cout << solution(6, vector<vector<int>>{{3, 6},
                                            {4, 3},
                                            {3, 2},
                                            {1, 3},
                                            {1, 2},
                                            {2, 4},
                                            {5, 2}}) << '\n';

    return 0;
}