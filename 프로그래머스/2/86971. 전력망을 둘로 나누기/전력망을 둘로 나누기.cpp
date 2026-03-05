#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<vector<int>> graph;
vector<bool> is_visited;
int cnt;

void setup(int n) {
    is_visited = vector<bool> (n + 1, false);
}

void dfs(int num, int v1, int v2) {
    for (int i = 0; i < graph[num].size(); i++) {
        int next_num = graph[num][i];
        
        if (is_visited[next_num]) continue;
        if ((num == v1 && next_num == v2) || (num == v2 && next_num == v1)) continue;
        
        cnt++;
        is_visited[next_num] = true;
        dfs(next_num, v1, v2);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    graph = vector<vector<int>> (n + 1);
    
    for (const auto& w : wires) { // 인접 리스트 그래프 형성
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    
    int hehe = 0;
    for (const auto& w : wires) { // wire 하나씩 끊고 트리 원소 세기 => cnt, n - cnt
        setup(n);
        is_visited[1] = true;
        cnt = 1;
        dfs(1, w[0], w[1]);
        if (abs(n - 2*cnt) < answer) answer = abs(n - 2*cnt);
        hehe++;
    }
    
    // for (int i = 1; i <= n; i++) { // 인접 리스트 그래프 출력
    //     for (int j = 0; j < graph[i].size(); j++)
    //         cout << graph[i][j] << ' ';
    //     cout << '\n';
    // }
    
    return answer;
}