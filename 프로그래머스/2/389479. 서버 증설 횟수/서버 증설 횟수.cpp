#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = 0;
    queue<pair<int, int>> expired;
    
    for (int i = 0; i < 24; i++) {
        if (expired.front().first == i) {
            n -= expired.front().second;
            expired.pop();
        }
        
        if (players[i] >= (n + 1) * m) {
            int next_n = players[i] / m;
            int gap = next_n - n;
            answer += gap;
            n = next_n;
            expired.push({i + k, gap}); 
        }
    }
    
    return answer;
}