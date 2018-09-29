//
// Created by mac on 2018. 9. 29..
//

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    string input1;
    string input2;

    cin >> input1;
    cin >> input2;

    bitset<100000> a(input1);
    bitset<100000> b(input2);


    cout << (a & b) << '\n';
    cout << (a | b) << '\n';
    cout << (a ^ b) << '\n';
    cout << (~a) << '\n';
    cout << (~b) << '\n';

    return 0;

}
