//
// Created by SUN on 2019-01-02.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> hash;

    // map에 전화번호부를 모두 등록시킨다.
    for (string x: phone_book) {
        hash.insert({x, 1});
    }

    // 전화번호의 접미어가 될 수 있는것을 찾아서 map에 등록되어있는지 찾는다.
    for (string x: phone_book) {
        for (int i = 1; i <= x.size() - 1; i++) {
            if (hash.count(x.substr(0, i))) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    cout << solution(vector<string>{"123", "456", "789"}) << '\n';

    return 0;
}