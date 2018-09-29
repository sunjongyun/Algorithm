//
// Created by mac on 2018. 9. 29..
//
#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> q;
    int n;
    int m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    for (int i = 1; i <= n - 1; i++) {

        for (int j = 0; j < m; j++) {
            int tmp = q.front();
            if (j != m - 1) {
                q.pop();
                q.push(tmp);
            } else {
                cout << tmp << ", ";
                q.pop();
            }

        }

    }

    int num;
    num = q.front();
    cout << num << ">";
    return 0;
}


