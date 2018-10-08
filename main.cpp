#include <iostream>
#include <functional>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    vector<int> a = {3, 1, 2};
    sort(a.begin(), a.end());

    do {
        for (int x: a) {
            cout << x << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

    /* 1 2 3
     * 1 3 2
     * 2 1 3
     * 2 3 1
     * 3 1 2
     * 3 2 1  */


    return 0;
}


