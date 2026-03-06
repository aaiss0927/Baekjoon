#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> graph;
vector<int> dist;
queue<int> q;
int maxi = -1;

void bfs() {
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (const auto& g : graph[cur]) {
            int next = g;
            if (dist[next] != -1) continue;
            
            dist[next] = dist[cur] + 1;
            if (dist[next] > maxi) maxi = dist[next];
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph = vector<vector<int>> (n + 1);
    dist = vector<int> (n + 1, -1);
    
    for (const auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dist[1] = 0;
    q.push(1);
    bfs();
    
    for (int i = 1; i <= n ; i++) {
        if (dist[i] == maxi) answer++;
    }
    
    // for (int i = 1; i <= n ; i++) {
    //     for (int j = 0; j < graph[i].size(); j++)
    //         cout << graph[i][j] << ' ';
    //     cout << '\n';
    // }
    
    return answer;
}

// 2 <= v <= 20000
// 1 <= e <= 50000