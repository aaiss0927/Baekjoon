#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int get_max(queue<int> q) {
    vector<int> temp;
    
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    
    return *max_element(temp.begin(), temp.end());
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    queue<int> idx;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push(priorities[i]);
        idx.push(i);
    }
    
    while (!q.empty()) {
        int max_prior = get_max(q);
        
        if (q.front() < max_prior) {
            q.push(q.front());
            q.pop();
            idx.push(idx.front());
            idx.pop();
        }
        
        else {
            q.pop();
            answer++;
            if (idx.front() == location) break;
            idx.pop();
        }
    }
    
    return answer;
}