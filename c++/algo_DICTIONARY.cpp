//
// Created by SUN on 2019-01-09.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;
vector<vector<int>> adj; //adj[i][j] : i문자가 j문자보다 위상이 높으면 1로 기록
vector<int> seen; // 해당 문자열을 방문했는가. 1: 방문, 0:아직 방문X
vector<int> order; // 문자의 위상 순서

void makeGraph(int n, vector<string> &dic) {
    adj = vector<vector<int>>(MAX, vector<int>(MAX, 0));

    // adj[here][there]   here: there문자보다 위상이 높다, there: here문자열보다 위상이 낮다.
    for (int i = 0; i < n - 1; i++) {
        int len = min(dic[i].size(), dic[i + 1].size());

        // len까지만 하는 이유
        // ex ) A문자열 : time, B문자열 : timebutton 인 경우처럼 A문자열이 B문자열의 접두사인 경우를
        // 같이 처리하기 위함.
        for (int k = 0; k < len; k++) {
            if (dic[i][k] != dic[i + 1][k]) {
                int here = dic[i][k] - 'a';
                int there = dic[i + 1][k] - 'a';
                adj[here][there] = 1;
                break;
            }
        }
    }

}

void dfs(int here) {
    seen[here] = 1;

    for (int there = 0; there < MAX; there++) {
        if (!seen[there] && adj[here][there] == 1) {
            dfs(there);
        }
    }

    order.push_back(here);
}

vector<int> topologicalSort() {
    seen = vector<int>(MAX, 0);
    order.clear();

    for (int here = 0; here < MAX; here++) {
        if (!seen[here]) {
            dfs(here);
        }
    }

    reverse(order.begin(), order.end());
    // 사이클이 만들어지는지 확인
    // here -> there로 위상인데, there-> here로 위상일 경우 잘못된 결과임.
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (adj[order[j]][order[i]] == 1) {
                return vector<int>{};
            }
        }
    }

    return order;
}

string solution(int n, vector<string> &dic) {
    string answer = "";

    // 1. 먼저 그래프를 만들어야 한다.
    makeGraph(n, dic);

    auto ret = topologicalSort();

    if (ret.empty()) {
        answer = "INVALID HYPOTHESIS";
    } else {
        for (int x: ret) {
            answer += char(x + 'a');
        }
    }

    return answer;
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        cin >> n;
        vector<string> dic(n);

        for (int i = 0; i < n; i++) {
            cin >> dic[i];
        }

        string ans = solution(n, dic);

        cout << ans << '\n';
    }

    return 0;
}