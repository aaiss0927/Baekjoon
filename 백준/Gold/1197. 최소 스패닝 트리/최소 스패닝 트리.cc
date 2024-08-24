#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

bool finished() {
	for (auto temp : visited) {
		if (temp == false)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	int v, e; cin >> v >> e;
	graph = vector<vector<pair<int, int>>>(v + 1);
	visited = vector<bool>(v + 1);
	visited[0] = true;
	int answer = 0;

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	visited[1] = true;
	for (auto g : graph[1])
		pq.push(g);

	while (!finished()) {
		int connected_v, w;
		tie(connected_v, w) = pq.top(); pq.pop();

		if (visited[connected_v])
			continue;

		visited[connected_v] = true;
		answer += w;

		for (auto g : graph[connected_v]) {
			if (visited[g.first])
				continue;

			pq.push(g);
		}
	}

	cout << answer;
}