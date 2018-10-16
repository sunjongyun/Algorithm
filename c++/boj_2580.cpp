//
// Created by mac on 2018. 10. 8..
// 미완성

#include <iostream>

using namespace std;

int map[9][9];
int n = 9;
int zero_num = 0;
int garo[9];
int sero[9];
int region[9];
bool num[10];
void init() {
    for (int i = 0; i < n; i++) {
        garo[i] = 0;
        sero[i] = 0;
        region[i] = 0;
    }
}

void pushMap(string input, int i) {
    if (input == "garo") {
        int sum=0;
        int index_j;
        for (int j = 0; j < n; ++j) {
            if (map[i][j]==0){
                garo[i]--;
                sero[j]--;
                region[(i/3)*3+j/3]--;

            }
            sum+=map[i][j];
        }
        map[i][j]=45-sum;
    } else if (input == "sero") {
        for (int j = 0; j <n ; ++j) {
            if (map[j][i]==0){
                garo[j]--;
                sero[i]--;
                region[(j/3)*3+i/3]--;
                map[j][i]=

            }
        }

    } else if (input == "3x3") {
        int start_i;
        int start_j;
        if (i/3==0){
            start_i=0;
        }else if (i/3==1){
            start_i=3;
        }else if (i/3==2){
            start_i=6
        }
        if (i%3==0){
            start_j=0;
        }else if (i%3==1){
            start_j=3;
        }else if (i%3==2){
            start_j=6;
        }

        for (int a=start_i; a<start_i+3; a++){
            for (int b=start_j; b<start_j+3; b++){
                if (map[a][b]==0){

                }
            }
        }

    }
}

int main() {

    init();

    //drowing map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                zero_num++;
                garo[i]++;
                sero[j]++;
                region[(i / 3) * 3 + j / 3];
            }
        }
    }

    while (zero_num != 0) {
        for (int i = 0; i < n; i++) {
            // 가로에서 찾았을 때
            if (garo[i] == 1) {
                pushMap("garo", i);
            }
            // 세로에서 찾았을 때
            if (sero[i] == 1) {
                pushMap("sero", i);
            }
            // 3x3에서 찾았을때
            if (region[i] == 1) {
                pushMap("3x3", i);
            }
        }


    }


    return 0;
}