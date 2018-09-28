#include <iostream>
#include <functional>
#include <list>

using namespace std;


int main() {

    function<void(list<int> &)> print = [](list<int> &param_l) {
        for (int x : param_l) {
            cout << x << ' ';
        }
        cout << '\n';
    };

    list<int> l = {2, 1, -5, 4, -3, 6, -7};
    print(l); //2 1 -5 4 -3 6 -7

    l.sort();
    print(l); // -7 -5 -3 1 2 4 6

    l.sort(greater<int>());
    print(l); // 6 4 2 1 -3 -5 -7

    l.sort([](int &u, int &v) {
        return abs(u) < abs(v);
    });
    print(l); //1 2 -3 4 -5 6 -7

    l.reverse();
    print(l); //-7 6 -5 4 -3 2 1

    return 0;
}



