//
// Created by mac on 2018. 10. 2..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int kor;
    int eng;
    int math;
    string name;
};

bool cmp(const Student &u, const Student &v) {
    if (u.kor == v.kor) {
        if (u.eng == v.eng) {
            if (u.math == v.math) {
                return u.name < v.name;
            } else {
                return u.math > v.math;
            }
        } else {
            return u.eng < v.eng;
        }
    } else {
        return u.kor > v.kor;
    }
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

    for (Student s : v) {
        cout << s.name << '\n';
    }

    return 0;
}