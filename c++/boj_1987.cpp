//
// Created by SUN on 2018-10-07.
//

#include <iostream>
#include <vector>
using namespace std;

int R=0;
int C=0;

int max=0; //지나온 길의 최대값

vector<bool> street; // 지나온 길
//bool street['Z'-'A'+1];
vector<int,vector<bool>> checked;

void dfs(int r, int c){

    for (int k=0; k<4; k++){

    }
}

int main()
{
    cin >> R >> C;

    char map[R][C];

    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin >> map[i][j];
        }
    }

    //street 초기화
    for (int i='A'; i<='Z'; i++){
        street[i]=0;
    }

    //checked초기화
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            checked[i][j]=false;
        }
    }
    street[map[0][0]]=1;
    dfs(0,0);


    return 0;
}