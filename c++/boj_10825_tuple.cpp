//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Student {
    string name;
    int kor;
    int eng;
    int math;
};

bool cmp(const Student &u, const Student &v) {
    return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}

int main() {
    int n;
    cin >> n;

    vector<Student> v;
    while (n--) {
        Student tmp;
        cin >> tmp.name >> tmp.kor >> tmp.eng >> tmp.math;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    for (Student st:v) {
        cout << st.name << '\n';
    }


    return 0;
}