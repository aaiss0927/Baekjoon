#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(1001);
bool visited[1001]{ false };

void dfs(int v) {
	visited[v] = true;
	for (auto i : graph[v]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
}