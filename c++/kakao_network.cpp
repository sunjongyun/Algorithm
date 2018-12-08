//
// Created by SUN on 2018-12-08.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int checked[201]; // visited check array

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // initialize
    memset(checked, 0, sizeof(checked));

    queue<int> q;
    int size = computers.size();

    for (int i = 0; i < size; i++) {

        // Proceed to not visit
        if (!checked[i]) {
            checked[i] = 1; // true

            for (int j = 0; j < size; j++) {
                // Finds connected nodes that are not themselves.
                if (computers[i][j] == 1 && i != j) {
                    if (!checked[j]) {
                        q.push(j);
                        checked[j] = 1;
                    }
                }

            }

            // Continue searching for connected nodes that have not yet visited.
            while (!q.empty()) {
                int now = q.front();
                q.pop();

                // Finds connected nodes that are not themselves.
                for (int j = 0; j < size; j++) {
                    if (computers[now][j] == 1 && i != j) {
                        if (!checked[j]) {
                            q.push(j);
                            checked[j] = 1;
                        }
                    }
                }
            }


            // When one network traversal is completed, the answer value is incremented by one.
            answer++;
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> v(3);

    v[0].push_back(1);
    v[0].push_back(1);
    v[0].push_back(0);

    v[1].push_back(1);
    v[1].push_back(1);
    v[1].push_back(1);

    v[2].push_back(0);
    v[2].push_back(1);
    v[2].push_back(1);

    int ans = solution(3, v);

    cout << ans << '\n';

    return 0;
}