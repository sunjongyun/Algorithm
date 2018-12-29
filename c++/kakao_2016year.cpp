//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";

    string YOIL[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int days = 0;
    int pastMonth = a - 1;

    for (int i = 0; i < pastMonth; i++) {
        days += month[i];
    }

    days += (b - 1);


    answer = YOIL[days % 7];


    return answer;
}


int main() {

    auto ans = solution(5, 24);

    cout << ans << '\n';

    return 0;
}

