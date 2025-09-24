#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g;
vector<int> dist;
vector<bool> is_visited;
queue<int> q;
int maxi;

void bfs() {
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (auto it = g[cur].begin(); it != g[cur].end(); it++) {
            int next = *it;
            
            if (!is_visited[next]) {
                is_visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
                if (maxi < dist[next]) maxi = dist[next];
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    g = vector<vector<int>>(n + 1, vector<int>());
    dist = vector<int>(n + 1, 0);
    is_visited = vector<bool>(n + 1, false);
    maxi = 0;
    
    for (auto it = edge.begin(); it != edge.end(); it++) {
        int first = (*it)[0];
        int second = (*it)[1];
        g[first].push_back(second);
        g[second].push_back(first);
    }
    
    q.push(1);
    is_visited[1] = true;
    bfs();
    
    for (int i = 2; i <= n; i++)
        if (dist[i] == maxi) answer++;

    return answer;
}