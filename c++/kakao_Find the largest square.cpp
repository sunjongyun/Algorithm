//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include<vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    /* row는 위에서 아래로 column은 왼쪽에서 오른쪽으로 진행한다.
     * board[i][j]= MIN( board[i-1][j-1], board[i-1][j], board[i][j-1] ) + 1
     * 의 값이 board[i][j]위치에서 만들 수 있는 최대 정사각형의 넓이 이다.
     * 2중 for문으로 board를 순회하는데, board[i][j]의 위치에서 계산할때는
     * 이미 board[i-1][j-1], board[i-1][j], board[i][j-1]을 계산하였기 때문에 계산 가능하다.
     * 예를 들어 [i-1][j-1], [i-1][j], [i][j-1] 위치에서 한변의 길이가 2인 정사각형을 만들 수 있다고
     * 가정하면 [i][j]에선 한변의 길이가 3인 정사각형을 만들 수 있다는 공식이다.
     * */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    int smallest = min(board[i - 1][j - 1], board[i - 1][j]);
                    smallest = min(smallest, board[i][j - 1]);
                    board[i][j] = smallest + 1;
                    answer = answer < board[i][j] ? board[i][j] : answer;
                } else {
                    board[i][j] = 1;
                    answer = answer < board[i][j] ? board[i][j] : answer;
                }
            }
        }
    }

    return answer * answer;
}

int main() {
    cout << solution(vector<vector<int>>{{0, 0, 1, 1},
                                         {1, 1, 1, 1}});

    return 0;
}