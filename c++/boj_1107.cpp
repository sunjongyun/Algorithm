//
// Created by SUN on 2018-10-03.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int initial_num = 100;
bool button_breaked[10];

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        button_breaked[input] = true;
    }

    //i ) +,-버튼만 이용하는 경우
    int ans1 = abs(n - initial_num);


    //ii) 번호를 입력하여 채널 이동 후, +,-버튼으로 조작하는 방법
    int ans2 = 987654321;
    for (int i = 0; i <= 1000000; i++) {
        int len = 0;
        int tmp = i;
        bool isbutton = true;

        if (tmp == 0) {
            if (button_breaked[0]) {
                isbutton = false;
            } else {
                len++;
            }
        }

        while (tmp) {
            int b = tmp % 10;
            tmp = tmp / 10;
            if (button_breaked[b]) {
                isbutton = false;
                break;
            }
            len++;
        }


        if (isbutton) {
            if (ans2 > (len + abs(n - i))) {
                ans2 = len + abs(n - i);
            }
        }
    }

    cout << ((ans1 < ans2) ? ans1 : ans2) << '\n';

    return 0;
}