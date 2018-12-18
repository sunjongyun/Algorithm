//
// Created by SUN on 2018-12-18.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


long long getLength(pair<long long, long long> p) {
    return p.first * p.first + p.second * p.second;
}


long long solution(int n, int k, vector<vector<pair<long long, long long>>> fishing) {
    long long answer = 0;

    vector<long long> areas;

    for (int area = 0; area < n; area++) {
        long long biggest = 0;
        for (int i = 0; i < fishing[area].size(); i++) {
            long long length = getLength(fishing[area][i]);
            biggest = length > biggest ? length : biggest;
        }
        areas.push_back(biggest);
    }

    sort(areas.begin(), areas.end());

    answer = areas[k - 1];

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);

    int n, k;

    scanf("%d %d", &n, &k);
    int cnt = 0;
    vector<vector<pair<long long, long long>>> fishing(n, vector<pair<long long, long long>>());

    while (cnt != n) {

        int num;
        scanf("%d", &num);

        for (int i = 0; i < num; i++) {
            long long x;
            long long y;
            scanf("%lld %lld", &x, &y);
            fishing[cnt].push_back({x, y});
        }

        cnt++;
    }

    long long ans = solution(n, k, fishing);

    printf("%lld.00", ans);

    return 0;
}