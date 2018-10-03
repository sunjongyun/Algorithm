//
// Created by SUN on 2018-10-02.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std;

char cmd[101];

int main() {

    int m;
    cin >> m;

    int res = 0;
    while (m--) {
        scanf("%s", cmd);

        if (!strcmp(cmd, "add")) {
            int x;
            scanf("%d", &x);
            x--;
            res = res | (1 << x);
        } else if (!strcmp(cmd, "remove")) {
            int x;
            scanf("%d", &x);
            x--;
            res = res & ~(1 << x);
        } else if (!strcmp(cmd, "check")) {
            int x;
            scanf("%d", &x);
            x--;
            int flag = (res & (1 << x));
            if (flag) {
                puts("1");
            } else {
                puts("0");
            }
        } else if (!strcmp(cmd, "toggle")) {
            int x;
            scanf("%d", &x);
            x--;
            res = res ^ (1 << x);
        } else if (!strcmp(cmd, "all")) {
            res = (1 << 20) - 1;
        } else if (!strcmp(cmd, "empty")) {
            res = 0;
        }


    }

    return 0;
}