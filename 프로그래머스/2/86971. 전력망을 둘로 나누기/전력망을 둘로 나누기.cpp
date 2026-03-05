#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<vector<bool>> graph;
vector<bool> is_visited;
int cnt, cnt1, cnt2;
int answer = INT_MAX;

void setup(int n) {
    is_visited = vector<bool> (n + 1, false);
}

void dfs(int n, int num) {    
    for (int i = 1; i <= n; i++) {
        if (!is_visited[i] && graph[num][i]) {
            is_visited[i] = true;
            dfs(n, i);
            cnt++;
        }
    }
}

void solve(int n) {
    setup(n);
    cnt = 1;
    bool flag = false;
    
    for (int i = 1; i <= n; i++) {
        if (is_visited[i]) continue;
        
        // cout << "노드" << i << "진입 ";
        is_visited[i] = true;
        cnt = 1;
        
        if (!flag) {
            dfs(n, i);
            cnt1 = cnt;
        } 
        else {
            dfs(n, i);
            cnt2 = cnt;
        }
        
        flag = true;
    }
    // cout << "cnt1: " << cnt1 << " cnt2: " << cnt2;
    
    int temp = abs(cnt1 - cnt2);
    if (temp < answer) answer = temp;
}

int solution(int n, vector<vector<int>> wires) {
    graph = vector<vector<bool>> (n + 1, vector<bool>(n + 1));
    
    for (const auto& w : wires)
        graph[w[0]][w[1]] = graph[w[1]][w[0]] = true;
    
    int hehe = 0;
    for (const auto& w : wires) {
        graph[w[0]][w[1]] = graph[w[1]][w[0]] = false;
        // cout << "wires[" << hehe << "] 삭제: "; 
        solve(n);
        // cout << '\n';
        graph[w[0]][w[1]] = graph[w[1]][w[0]] = true;
        hehe++;
    }
    
    return answer;
}

// 1
//
// 2
// 3
// 4

// 2 <= n <= 100
// wires.size() = n - 1
// wires = [[v1, v2], ,,, ,]  v1-v2 연결됨
// 1 <= v1 < v2 <= n
// result: 두 트리 내 노드 개수 차이 절대값
// 하나씩 끊고 두 트리에서 각각 dfs로 노드 개수 확인