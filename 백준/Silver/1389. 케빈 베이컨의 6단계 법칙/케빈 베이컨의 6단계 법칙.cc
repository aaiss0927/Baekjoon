#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[101];
vector<bool> visited;
vector<vector<int>> path;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto i : graph[cur]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				path[x][i] = path[x][cur] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	path = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		visited = vector<bool>(N + 1, false);
		bfs(i);
	}

	vector<int> result(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result[i] += path[i][j];
		}
	}

	int min = result[1];
	int min_idx = 1;
	for (int i = 2; i <= N; i++) {
		if (result[i] < min) {
			min = result[i];
			min_idx = i;
		}
	}
	cout << min_idx;
}