#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (const auto& s : scoville) pq.push(s);
    
    while (!pq.empty() && pq.top() < K) {
        long long result, min, second_min;
        min = pq.top(); pq.pop();
        
        if (pq.empty()) {
            pq.push(min);
            break;
        }
        
        second_min = pq.top(); pq.pop();
        
        if (second_min == 0) return -1;
        
        result = min + 2 * second_min;
        pq.push(result);
        answer++;
    }
    
    if (pq.top() < K) answer = -1;
    return answer;
}

// 0 1 2 3   k = 10
// 0 0 2 3

// result = min + 2 * second_min
// while (!모든 원소 k 이상) => while(pq.top() < k)
// 안 되면 -1
// 2 <= n <= 10^6
// 0 <= scoville[i] <= 10^6
// 0 <= k <= 10^9