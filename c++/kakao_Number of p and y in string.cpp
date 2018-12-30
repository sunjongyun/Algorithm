//
// Created by SUN on 2018-12-30.
//

#include <iostream>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {

    int yNum=0;
    int pNum=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='y' || s[i]=='Y') yNum++;
        if(s[i]=='p' || s[i]=='P') pNum++;
    }

    return yNum==pNum;
}

int main() {
    bool ans = solution("Pyy");

    if (ans) {
        cout << "true" << '\n';
    } else cout << "false" << '\n';

    return 0;
}