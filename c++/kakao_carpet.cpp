//
// Created by SUN on 2019-01-02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int total = brown + red;

    for (int width = 3; width <= total; width++) {
        if (total % width == 0) {
            int height = total / width;
            if (brown == (width * 2 + (height - 2) * 2) && width >= height) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}

int main() {
    auto ans = solution(24, 24);
    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}