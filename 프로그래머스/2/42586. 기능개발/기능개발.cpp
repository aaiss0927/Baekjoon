#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> answer;
    vector<int> rests;
    
    for (int i = 0; i < n; i++) {
        double temp = (100 - progresses[i]) / double(speeds[i]);
        int rest = (temp > int(temp)) ? int(temp) + 1 : int(temp);
        
        rests.push_back(rest);
    }
    
    int cur = 1;
    int cnt = 1;
    for (int i = 0; i < n && cur < n;) {
        while ((cur < n) && (rests[i] >= rests[cur])) {
            cnt++;
            cur++;
        }
        
        answer.push_back(cnt);
        cnt = 1;
        i = cur;
        cur++;
        
        if (i < n && cur >= n) answer.push_back(cnt);
    }
    
    return answer;
}

// 7 3 9 3   2 2
// 15 10 1 1 20 1    4 2