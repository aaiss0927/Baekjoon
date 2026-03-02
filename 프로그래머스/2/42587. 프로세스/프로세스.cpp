#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int len = priorities.size();
    queue<pair<int, int>> q;
    
    for (int i = 0; i < len; i++)
        q.push({priorities[i], i});
    
    while (1) {
        auto max_idx = max_element(priorities.begin(), priorities.end());
        auto max_val = *max_idx;
        
        int val = q.front().first;
        int idx = q.front().second; q.pop();
        
        if (val >= max_val) {
            answer++;
            if (idx == location) break;
            priorities.erase(max_idx);
        } 
        
        else q.push({val, idx});
    }
    
    return answer;
}


// 1 1 9 1 1 1
// 1 9 1 1 1 1
// 9 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1
// 1 1 1
// 1 1
// 1