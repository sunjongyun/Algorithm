//
// Created by SUN on 2019-01-03.
//
#include <iostream>
#include <string>
using namespace std;

string solution(string s) {
    s[0]=toupper(s[0]);
    int index=1;
    while(index<s.size()){
        if(s[index-1]==' '){
            s[index]=toupper(s[index]);
        }else {
            s[index]=tolower(s[index]);
        }
        index++;
    }

    return s;
}

int main() {
    cout << solution("3people unFollowed me") << '\n';
    return 0;
}