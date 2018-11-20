//
// Created by SUN on 2018-11-20.
//

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

vector<int> divide(int num) {
    vector<int> result;

    int first = num / 100;
    int second = (num / 10) % 10;
    int third = (num % 10);

    result.push_back(first);
    result.push_back(second);
    result.push_back(third);


    return result;
}

bool IsAlrightPick(int pick) {
    bool res = false;
    set<int> s;

    vector<int> d = divide(pick);
    s.insert(d[0]);
    s.insert(d[1]);
    s.insert(d[2]);

    // 각자 서로 다른 1~9까지 3자리 임의의 숫자, '0'이 들어가는 것을 허용X
    if (s.size() == 3 && s.count(0) == 0) {
        res = true;
    }

    return res;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    // 답을 정해놓고 추리를 해나아간다. 최소값이 123부터 3자리 숫자 끝인 999까지 조사한다.
    for (int pick = 123; pick <= 999; pick++) {
        int cnt = 0; //조건이 몇개 맞는지 조사한다.

        if (IsAlrightPick(pick) == false) { //pick의 유효성 검사
            continue;
        }

        for (int i = 0; i < baseball.size(); i++) {
            vector<int> v = baseball[i];
            int num = v[0];
            vector<int> pickValues = divide(pick);
            vector<int> numValues = divide(num);

            bool checked[10]; // 1~9까지의 숫자를 체크
            memset(checked, false, 10); // checked의 원소들을 모두 false로 초기화
            checked[pickValues[0]] = true;
            checked[pickValues[1]] = true;
            checked[pickValues[2]] = true;

            int strAndBall = 0; // strike + ball의 갯수
            for (int j = 0; j < 3; j++) {
                if (checked[numValues[j]]) {
                    strAndBall++;
                }
            }

            int strike = 0;
            for (int j = 0; j < 3; j++) {
                if (pickValues[j] == numValues[j]) {
                    strike++;
                }
            }

            int ball = strAndBall - strike;

            if (v[1] == strike && v[2] == ball) {
                cnt++;
            } else {
                break;
            }

        }
        if (cnt == baseball.size()) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> baseball(4);

    baseball[0].push_back(123);
    baseball[0].push_back(1);
    baseball[0].push_back(1);

    baseball[1].push_back(356);
    baseball[1].push_back(1);
    baseball[1].push_back(0);

    baseball[2].push_back(327);
    baseball[2].push_back(2);
    baseball[2].push_back(0);

    baseball[3].push_back(489);
    baseball[3].push_back(0);
    baseball[3].push_back(1);

    int ans = solution(baseball);

    cout << ans << '\n';
    return 0;
}