//
// Created by SUN on 2018-10-06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int l;
    int c;

    cin >> l >> c;

    vector<char> v; // alphabet group
    for (int i = 0; i < c; i++) {
        char input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    vector<int> pmt; //permutation
    for (int i = 0; i < l; i++) {
        pmt.push_back(0);
    }
    for (int i = 0; i < c - l; i++) {
        pmt.push_back(1);
    }
    sort(pmt.begin(), pmt.end());


    do {
        string str;

        // 문자열을 만든다.
        //문자열이 조건에 성립하는지 조사
        //최소 한개의 모음과 두개의 자음
        int mo = 0;
        int ja = 0;
        for (int i = 0; i < pmt.size(); i++) {
            if (pmt[i] == 0) {
                str.push_back(v[i]);
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
                    mo++;
                } else {
                    ja++;
                }
            }
        }

        if (mo >= 1 && ja >= 2) {
            //str에 들어있는 문자열 출력
            cout << str << '\n';
        }


    } while (next_permutation(pmt.begin(), pmt.end()));


    return 0;
}