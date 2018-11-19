//
// Created by mac on 2018. 11. 12..
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    reverse(commands.begin(), commands.end());

    while (!commands.empty()) {

        vector<int> c = commands.back();
        commands.pop_back();


        //부분 집합을 가져온다.
        vector<int> a;
        for (int i = c[0] - 1; i < c[1]; i++) {
            a.push_back(array[i]);
        }

        sort(a.begin(), a.end());

        answer.push_back(a[c[2]-1]);
    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};

    vector<vector<int>> commands = {{2, 5, 3},
                                    {4, 4, 1},
                                    {1, 7, 3}};


    vector<int> ans = solution(array, commands);

    for (auto x: ans) {
        cout << x << '\n';
    }

    return 0;
}


//[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]