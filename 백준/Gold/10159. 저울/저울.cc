#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> cnt;

void dfs(int cur, int num) {
	for (int next : graph[cur]) {
		if (visited[next])
			continue;

		visited[next] = true;
		cnt[num]++;
		cnt[next]++;
		dfs(next, num);
	}
}

int main() {
	int m;
	cin >> n >> m;
	graph = vector<vector<int>>(n + 1);
	cnt = vector<int>(n + 1);

	while (m--) {
		int s, e; cin >> s >> e;
		graph[s].push_back(e);
	}

	for (int i = 1; i <= n; i++) {
		visited = vector<bool>(n + 1, false);
		visited[i] = true;
		dfs(i, i);
	}

	for (int i = 1; i <= n; i++) {
		cout << n - 1 - cnt[i] << '\n';
	}
}