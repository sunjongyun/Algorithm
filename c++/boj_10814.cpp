//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int age;
    string name;
};

bool cmp(const Person &u, const Person &v) {
    return u.age < v.age;
}

int main() {

    int n;
    cin >> n;

    vector<Person> v;
    while (n--) {
        Person tmp;
        cin >> tmp.age >> tmp.name;
        v.push_back(tmp);
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (Person p : v) {
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}