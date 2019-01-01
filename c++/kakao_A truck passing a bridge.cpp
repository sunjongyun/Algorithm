//
// Created by SUN on 2019-01-01.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int available = weight;
    vector<pair<int, int>> bridgeOnTrucks; // {트럭무게, 건너는 시간}
    while (!(bridgeOnTrucks.empty() && truck_weights.empty())) {
        answer++;
        //시간이 경과하면 트럭의 건너는시간을 1감소시킨다.
        //건너는 시간이 0이 된다면, 다리위에 있는 트럭을 뺀다.
        int n = bridgeOnTrucks.size();
        for (int i = n - 1; i >= 0; i--) {
            int &time = bridgeOnTrucks[i].second;
            time--;
            if (time == 0) {
                available += bridgeOnTrucks[i].first;
                bridgeOnTrucks.erase(bridgeOnTrucks.begin() + i);
            }
        }

        //다리에 트럭을 넣을 수 있으면 트럭을 싣는다.
        if (truck_weights.size() > 0 && available >= truck_weights[0]) {
            bridgeOnTrucks.push_back({truck_weights[0], bridge_length});
            available -= truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
    }

    return answer;
}

int main() {


    cout << solution(100, 100, vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << '\n';


    return 0;
}