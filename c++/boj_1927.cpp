//
// Created by mac on 2018. 9. 29..
//

#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        int x;
        scanf("%d", &x);

        if (x == 0) {
            if (q.size() == 0) {
                printf("0\n");
            } else {
                printf("%d\n", q.top());
                q.pop();
            }
        } else {
            q.push(x);
        }


    }


    return 0;
}


