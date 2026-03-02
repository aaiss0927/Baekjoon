#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void q_printer(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0;
    queue<int> bridge;
    queue<int> trucks;
    
    for (int i = 0; i < bridge_length; i++) bridge.push(0);
    for (int i = 0; i < truck_weights.size(); i++) trucks.push(truck_weights[i]);
    
    while (1) {
        if (total - bridge.front() + trucks.front() <= weight) {
            total += (trucks.front() - bridge.front());
            bridge.push(trucks.front()); trucks.pop();
        }
        
        else {
            total -= bridge.front();
            bridge.push(0);
        }
        bridge.pop();
        answer++;
        // cout << answer << " / ";
        // q_printer(bridge);
        
        if (trucks.empty()) {
            answer += bridge_length;
            break;
        }
    }
    
    
    return answer;
}

// _ _    7 4 5 6
// _ 7    4 5 6
// 7 _    4 5 6
// _ 4    5 6
// 4 5    6
// 5 _    6
// _ 6
// 6 _
// _ _