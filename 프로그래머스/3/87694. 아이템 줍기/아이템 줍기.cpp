#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int grid[101][101];
int dist[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

bool in_range(int x, int y) {
    return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

bool can_go(int x, int y) {
    return in_range(x, y) && grid[x][y] == 1 && !visited[x][y];
}

void setup() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            grid[i][j] = 0;
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
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
                dist[nx][ny] = dist[x][y] + 1;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

// 0: 기본 상태
// 1: true
// 2: false(절대 못 변함)

// 전부 0
// 현재 사각형 테두리 2가 아니었다면 1로 변환, 내부 2로 변환

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    setup();
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1, y1, x2, y2;
        x1 = rectangle[i][1] * 2;
        y1 = rectangle[i][0] * 2;
        x2 = rectangle[i][3] * 2;
        y2 = rectangle[i][2] * 2;
        
        for (int j = x1 + 1; j < x2; j++) {
            for (int k = y1 + 1; k < y2; k++)
                grid[j][k] = 2;
        }
        
        for (int j = x1; j <= x2; j++) {
            if (grid[j][y1] != 2)
                grid[j][y1] = 1;
            
            if (grid[j][y2] != 2)
                grid[j][y2] = 1;
        }
        
        for (int j = y1; j <= y2; j++) {
            if (grid[x1][j] != 2)
                grid[x1][j] = 1;
            
            if (grid[x2][j] != 2)
                grid[x2][j] = 1;
        }
    }
    
    visited[characterY * 2][characterX * 2] = true;
    q.push({characterY * 2, characterX * 2});
    bfs();
    answer = dist[itemY * 2][itemX * 2] / 2;
    
    return answer;
}

// 1. 바깥 둘레 따기(캐릭터 이동 경로)
// 2. 이동 경로 좌표로 표현
// 3. BFS로 최단 경로 (character - item)