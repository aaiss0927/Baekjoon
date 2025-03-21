#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur) {
    for (int i = 0; i < n; i++) {
        if (graph[cur][i] && !visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}

int solution(int input_n, vector<vector<int>> computers) {
    int answer = 0;
    n = input_n;
    graph = computers;
    visited = vector<bool> (n, false);
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        dfs(i);
        answer++;
    }
    
    
    return answer;
}

// 1 1 0
// 1 1 1
// 0 1 1