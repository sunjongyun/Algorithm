//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    multimap<string, string> map1;
    for (auto x: clothes) {
        map1.insert({x[1], x[0]});
    }

    for (auto it = map1.begin(); it != map1.end(); it = map1.upper_bound(it->first)) {
        answer *= (map1.count(it->first) + 1);
    }

    return answer - 1;
}

int main() {
    cout << solution(vector<vector<string>>{{"yellow_hat",      "headgear"},
                                            {"blue_sunglasses", "eyewear"},
                                            {"green_turban",    "headgear"}}) << '\n';

    return 0;
}