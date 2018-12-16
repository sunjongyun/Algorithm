//
// Created by SUN on 2018-12-16.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

int dx[] = {0, 1, 0, -1}; // [0]: right, [1]: down, [2]:left, [3]:up
int dy[] = {1, 0, -1, 0}; // [0]: right, [1]: down, [2]:left, [3]:up

int getDir(int now_dir, char dir) {
    int next_dir = now_dir;
    if (dir == 'D') {
        next_dir++;
    } else if (dir == 'L') {
        next_dir--;
    }

    if (next_dir == -1) {
        next_dir = 3;
    } else if (next_dir == 4) {
        next_dir = 0;
    }

    return next_dir;
}

int solution(int n, int apples_num, int dir_num, vector<pair<int, int>> apples, vector<pair<int, char>> dir) {
    int cnt = 0;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0)); // 1-based, Initially initialized to zero
    int dir_index = 0;
    deque<pair<int, int>> snake;
    snake.push_back({1, 1}); //initialize

    // The place where the apples are placed is 1
    for (int i = 0; i < apples_num; i++) {
        map[apples[i].first][apples[i].second] = 1;
    }

    bool isFinish = false;
    int now_dir = 0; //init right direction
    while (!isFinish) {
        cnt++; //1초 증가

        auto now = snake.front();
        int nextX = now.first + dx[now_dir];
        int nextY = now.second + dy[now_dir];

        if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n) {
            snake.push_front({nextX, nextY});
            //The snake examines the body for overlap.
            for (int i = 1; i < snake.size(); i++) {
                if (nextX == snake[i].first && nextY == snake[i].second) {
                    break;
                }
            }
        } else {
            isFinish = true;
            break;
        }


        //If there is no apple in the next box, reduce the tail.
        if (map[nextX][nextY] == 0) {
            snake.pop_back();
        } else {
            map[nextX][nextY] = 0;
        }

        //Change the head direction of the snake.
        if (dir_index<dir.size() && dir[dir_index].first == cnt) {
            now_dir = getDir(now_dir, dir[dir_index].second);
            dir_index++;
        }

    }

    return cnt;
}


int main() {
    int n;

    int apples_num;
    int dir_num;

    cin >> n;
    cin >> apples_num;

    vector<pair<int, int>> apples(apples_num);
    for (int i = 0; i < apples_num; i++) {
        cin >> apples[i].first >> apples[i].second;
    }

    cin >> dir_num;
    vector<pair<int, char>> dir(dir_num);
    for (int i = 0; i < dir_num; i++) {
        cin >> dir[i].first >> dir[i].second;
    }

    int ans = solution(n, apples_num, dir_num, apples, dir);

    cout << ans << '\n';

    return 0;
}