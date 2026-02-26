#include <iostream>
#include <vector>
using namespace std;

int c, r;
bool is_visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_range(int x, int y) {
    return (x >= 1 && x <= c && y >= 1 && y <= r);
}

bool can_go(int x, int y) {
    return in_range(x, y) && !is_visited[x][y];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> c >> r;
    int k; cin >> k;
    
    int x, y, cur_k;
    x = y = cur_k = 1;
    int dir = 0;
    is_visited[x][y] = true;
    
    while (1) {
        if (cur_k == k) {
            cout << x << ' ' << y;
            return 0;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (!can_go(nx, ny)) {
            bool flag = false;
            
            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                
                if (can_go(nx, ny)) {
                    dir = i;
                    flag = true;
                    break;
                }
            }
            
            if (!flag) break;
        }
    
        is_visited[nx][ny] = true;
        x = nx; y = ny;
        cur_k++;
    }
    
    cout << 0;
}

// 순회해도 시간복잡도 충분