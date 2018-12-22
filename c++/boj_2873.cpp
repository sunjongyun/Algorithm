//
// Created by SUN on 2018-12-21.
//

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchMinimum(int r, int c, vector<vector<int>> &map) {
    int smallest = 123456789;
    int index_r = -1;
    int index_c = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((i + j) % 2 == 1) {
                if (smallest > map[i][j]) {
                    smallest = map[i][j];
                    index_r = i;
                    index_c = j;
                }
            }
        }
    }

    map[index_r][index_c] = -1;

    return make_pair(index_r, index_c);
}

void makeString(int r, int c, string &answer, pair<int, int> p) {
    int index_r = p.first;
    int index_c = p.second;

    bool isPass = false; // To avoid duplication if it is a pattern of "DR" and "UR".
    bool isUPandRight = false; //Should I put "UR"?
    bool isTrans = false; // If you pass a row with a pattern of "DR" and "UR", the "RRR ..." pattern will change to the "LLL ..." pattern.

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            if (!isTrans) {
                if ((i / 2) != (index_r / 2)) { // Is it the row that contains the patterns "DR" and "UR"?
                    if (i % 2 == 1) { // If it is an odd row, "RRRR ... D"
                        if (j == c - 1) { // Is it last?
                            answer += 'D';
                        } else {
                            answer += 'L';
                        }
                    } else { // If it is an even row, "LLLL ... D"
                        if (j == c - 1) { // Is it last?
                            answer += 'D';
                        } else {
                            answer += 'R';
                        }
                    }
                } else {
                    if (!isPass) {
                        if (j != index_c) {
                            if (isUPandRight) {
                                answer += "UR";
                                isUPandRight = false;
                            } else {
                                answer += "DR";
                                isUPandRight = true;
                            }
                        } else {
                            answer += "R";
                        }

                        if (j == c - 1) {
                            answer.erase(answer.end() - 1, answer.end());
                            answer += "D";
                            isTrans = true;
                            i++;
                        }
                    }

                    if (j == c - 1) {
                        isPass = true;
                    }
                }
            } else {
                if (i % 2 == 1) {
                    if (j == c - 1) {
                        answer += 'D';
                    } else {
                        answer += 'R';
                    }
                } else {
                    if (j == c - 1) {
                        answer += 'D';
                    } else {
                        answer += 'L';
                    }
                }
            }
        }
    }

}


string solution(int r, int c, vector<vector<int>> map) {
    string answer;

    auto p = searchMinimum(r, c, map);


    if (r % 2 == 0 && c % 2 == 0) {
        makeString(r, c, answer, p);
    } else if (r % 2 == 1) { // When row is odd, Visit all locations.
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i % 2 == 1) {
                    if (j == c - 1) {
                        answer += 'D';
                    } else {
                        answer += 'L';
                    }
                } else {
                    if (j == c - 1) {
                        answer += 'D';
                    } else {
                        answer += 'R';
                    }
                }
            }
        }
    } else if (c % 2 == 1) { // When column is odd, Visit all locations.
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (i % 2 == 1) {
                    if (j == r - 1) {
                        answer += 'R';
                    } else {
                        answer += 'U';
                    }
                } else {
                    if (j == r - 1) {
                        answer += 'R';
                    } else {
                        answer += 'D';
                    }
                }
            }
        }
    }

    answer.erase(answer.end() - 1, answer.end());

    return answer;
}


int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    vector<vector<int>> map(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    string ans = solution(r, c, map);

    cout << ans << '\n';


    return 0;
}