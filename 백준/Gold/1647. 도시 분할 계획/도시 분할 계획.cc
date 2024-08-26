#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> edges;
int cost;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;
	graph = vector<vector<pair<int, int>>>(n + 1);
	visited = vector<bool>(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	visited[1] = true;
	for (auto g : graph[1]) {
		pq.push(g);
	}

	int cond_cnt = 1;
	while (!pq.empty() && cond_cnt < n) {
		int w, v;
		tie(w, v) = pq.top(); pq.pop();

		if (visited[v])
			continue;

		visited[v] = true;
		edges.push_back(w);
		cond_cnt++;
		cost += w;

		for (auto g : graph[v])
			pq.push(g);
	}

	cost -= *max_element(edges.begin(), edges.end());
	cout << cost;
}