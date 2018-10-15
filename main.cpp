#include <iostream>
#include <functional>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>

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



