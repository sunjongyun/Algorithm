//
// Created by SUN on 2018-12-18.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s1, s2;
    cin >> s1 >> s2;

    vector<int> sample(s1);
    vector<int> min_sample(s1);
    vector<int> system(s2);
    vector<int> min_system(s2);

    for (int i = 0; i < s1; i++) {
        scanf("%d %d", &sample[i], &min_sample[i]);
    }

    for (int i = 0; i < s2; i++) {
        scanf("%d %d", &system[i], &min_system[i]);
    }


    for (int i = 0; i < s1; i++) {
        if (sample[i] != min_sample[i]) {
            cout << "Wrong Answer" << '\n';
            return 0;
        }
    }

    for (int i = 0; i < s2; i++) {
        if (system[i] != min_system[i]) {
            cout << "Why Wrong!!!" << '\n';
            return 0;
        }
    }

    cout << "Accepted" << '\n';


    return 0;
}