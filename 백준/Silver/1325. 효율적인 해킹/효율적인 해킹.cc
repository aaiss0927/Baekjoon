#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[10001];
vector<bool> visited;

void dfs(int x, int& cnt) {
	visited[x] = true;
	for (auto i : graph[x]) {
		if (!visited[i]) {
			cnt++;
			dfs(i, cnt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[v].push_back(u);
	}

	vector<int> cnt(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		visited = vector<bool>(N + 1, false);
		dfs(i, cnt[i]);
	}

	int max = cnt[1];
	for (int i = 2; i <= N; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == max) {
			cout << i << " ";
		}
	}
}