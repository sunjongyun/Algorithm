//
// Created by SUN on 2019-01-07.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void copyMap(map<string, multiset<string>> &dest, const map<string, multiset<string>> &ori) {
    for (auto x: ori) {
        auto it = x.second.begin();
        while (it != x.second.end()) {
            dest[x.first].insert(*it);
            ++it;
        }
    }
}

// cur : 현재 위치, routes : [key: start, value: end], sum:이동한 경로의 횟수, n:최종 이동경로의 횟수, make: 지나쳐 온 이동경로
vector<string> dfs(string cur, map<string, multiset<string>> routes, int sum, int n, vector<string> make) {

    // 모두 이동했을 경우 make를 반환
    if (sum == n) {
        return make;
    }

    //현재위치에서 다음위치로의 경로가 없다면 빈 vector<string>를 반환한다.
    if (routes[cur].empty()) {
        return vector<string>{};
    }

    map<string, multiset<string>> tmp;
    copyMap(tmp, routes);
    vector<string> answer;
    for (auto it = routes[cur].begin(); it != routes[cur].end(); ++it) {
        string next = *it;
        tmp[cur].erase(tmp[cur].find(next)); // 한개의 값만 지운다.
        make.push_back(next);
        answer = dfs(next, tmp, sum + 1, n, make);
        tmp[cur].insert(next);
        make.pop_back();

        // 모두 이동한 경로가 반환이 되면, 더 이상 다른 경로를 찾지 않는다.
        if (answer.size() > 0) {
            break;
        }
    }
    return answer;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    //multiset을 사용하는 이유는 알파벳순으로 end_point 경로가 저장이 되기 때문이다.
    map<string, multiset<string>> routes;

    for (auto x:tickets) {
        string start = x[0];
        string end = x[1];
        routes[start].insert(end);
    }

    string cur = "ICN";
    answer = dfs(cur, routes, 0, n, vector<string>{cur});

    return answer;
}

int main() {
    auto ans = solution({{"ICN", "SFO"},
                         {"ICN", "ATL"},
                         {"SFO", "ATL"},
                         {"ATL", "ICN"},
                         {"ATL", "SFO"}});

    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}