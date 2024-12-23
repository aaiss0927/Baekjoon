#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> finished;

void dfs(int cur) {
    visited[cur] = true;

    int next = graph[cur][0];

    if (!visited[next])
        dfs(next);

    else if (!finished[next]) {
        for (int i = next; i != cur; i = graph[i][0])
            cnt++;
        cnt++;
    }

    finished[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    while (T--) {
        cin >> n;
        cnt = 0;
        graph = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1, false);
        finished = vector<bool>(n + 1, false);

        for (int i = 1; i <= n; i++) {
            int num; cin >> num;
            graph[i].push_back(num);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;

            dfs(i);
        }

        cout << n - cnt << '\n';
    }
}