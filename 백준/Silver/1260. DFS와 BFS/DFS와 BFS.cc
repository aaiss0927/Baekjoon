#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (auto i : graph[x]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";
        for (auto i : graph[top]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < 1001; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    for (int i = 0; i < 1001; i++) {
        visited[i] = false;
    }
    cout << '\n';
    bfs(V);
}