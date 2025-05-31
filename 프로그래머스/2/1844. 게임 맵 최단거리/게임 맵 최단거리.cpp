#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<int>> dist;
queue<pair<int, int>> q;

bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool can_go(int x, int y) {
    return in_range(x, y) && map[x][y] && !visited[x][y];
}

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (can_go(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
            }
        }
    }
}

int solution(vector<vector<int>> input_maps) {
    int answer = 0;
    
    n = input_maps.size();
    m = input_maps[0].size();
    map = input_maps;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;
    bfs();
    answer = dist[n - 1][m - 1];
    
    if (answer == INT_MAX) answer = -1;
    
    return answer;
}


