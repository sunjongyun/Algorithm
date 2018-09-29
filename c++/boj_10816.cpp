
//
// Created by mac on 2018. 9. 29..
//

#include <iostream>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    multiset<int> cards;

    while (n--){
        int num;
        scanf("%d", &num);
        cards.insert(num);
    }

    int m;
    cin >> m;
    while (m--){
        int search;
        scanf("%d", &search);
        int x=cards.count(search);
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}