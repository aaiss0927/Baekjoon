#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int get_next_bridge_weights(queue<int>bridge, int next) {
    int sum = next;
    
    while (!bridge.empty()) {
        sum += bridge.front();
        bridge.pop();
    }
    
    return sum;
}

bool exit_condition(queue<int> bridge, queue<int> truck) {
    while (!bridge.empty()) {
        if (bridge.front() != 0) return false;
        bridge.pop();
    }
    
    if (truck.empty()) return true;
    else return false;
}

vector<int> my_copy(queue<int> q) {
    vector<int> temp;
    
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    
    return temp;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck;
    queue<int> bridge;
    
    for (int i = 0; i < truck_weights.size(); i++) truck.push(truck_weights[i]);
    for (int i = 0; i < bridge_length; i++) bridge.push(0);
    
    while (!exit_condition(bridge, truck)) {
        bridge.pop();
        
        if (!truck.empty() && get_next_bridge_weights(bridge, truck.front()) <= weight) {
            bridge.push(truck.front());
            truck.pop();
        }
        
        else bridge.push(0);
        answer++;
    }
    
    return answer;
}