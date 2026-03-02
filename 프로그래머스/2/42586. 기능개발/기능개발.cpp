#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> answer;
    queue<int> rests;
    
    for (int i = 0; i < n; i++)
        rests.push(int(ceil((100.0 - progresses[i]) / speeds[i])));
    
    while (!rests.empty()) {
        int val = rests.front(); rests.pop();
        int cnt = 1;
        
        while (!rests.empty() && val >= rests.front()) {
            cnt++;
            rests.pop();
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}

// 7 3 9   2 1
// 15 10 1 1 20 1    1 3 2