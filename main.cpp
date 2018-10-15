#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> ips;    //input string
vector<int> flb;    // flag bit ----> 1에 해당하는 것만 출력
vector<char> ans;   // 최종 정답
int L, C;
int mo; // mycount -> mo (모음)
int ja; // 자음 추가

int main() {
    scanf("%d %d", &L, &C);
    for (int c = 0; c < C; c++) {
        char inss;
        scanf(" %c", &inss); // cin 으로 바꿔보자
        ips.push_back(inss);
    }
    for (int l = 0; l < L; l++) {
        flb.push_back(1);
    }
    for (int l2 = 0; l2 < C - L; l2++) {
        flb.push_back(0);
    }

    sort(ips.begin(), ips.end());
    //sort(flb.begin(), flb.end(), greater<int>());
    do {
        mo = 0;
        ja = 0;
        ans.clear(); // vector<char> ans;
        for (int i = 0; i < ips.size(); i++) {
            if (flb[i]) {
                if (ips[i] == 'a' || ips[i] == 'e' || ips[i] == 'i' || ips[i] == 'o' || ips[i] == 'u') {
                    mo++;
                    ans.push_back(ips[i]);
                } else {
                    ja++;
                    ans.push_back(ips[i]);
                }
            }
        }
        if (ans.size() == L) {
            if (mo >= 1 && ja >= 2) {
                for (int i = 0; i < ans.size(); i++) {
                    printf("%c", ans[i]);            //최종 출력 정답
                }
                printf("\n");
            }
        }
    } while (prev_permutation(flb.begin(), flb.end()));    //flag bit 예를 들어 111100 이면 0~4까지만 출력

    ans.clear();
    ips.clear();
    flb.clear();
}