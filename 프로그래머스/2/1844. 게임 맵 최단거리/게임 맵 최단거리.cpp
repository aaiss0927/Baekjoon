#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<int>> maps;
vector<vector<bool>> visited;
vector<vector<int>> dist;
queue<pair<int, int>> q;

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool can_go(int x, int y) {
    return in_range(x, y) && !visited[x][y] && maps[x][y];
}

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (can_go(nx, ny)) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int solution(vector<vector<int>> input_maps) {
    int answer = 0;
    maps = input_maps;
    n = maps.size();
    m = maps[0].size();
    visited = vector<vector<bool>> (n, vector<bool> (m, false));
    dist = vector<vector<int>> (n, vector<int> (m, -1));
    dist[0][0] = 1;
    
    q.push({0, 0});
    visited[0][0] = true;
    bfs();
    answer = dist[n - 1][m - 1];
    
    return answer;
}