#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int v, e;
vector<vector<int>> graph;
vector<vector<int>> t_graph;
vector<bool> visited;
stack<int> s;
vector<int> scc;

void dfs(int cur) {
	for (int n : graph[cur]) {
		if (visited[n])
			continue;
		
		visited[n] = true;
		dfs(n);
		s.push(n);
	}
}

void t_dfs(int cur, int leader) {
	for (int n : t_graph[cur]) {
		if (visited[n])
			continue;

		visited[n] = true;
		scc[n] = leader;
		t_dfs(n, leader);
	}
}

void setup() {
	for (int i = 0; i < visited.size(); i++)
		visited[i] = false;
}

vector<vector<int>> get_transpose() {
	vector<vector<int>> t_graph(v + 1);

	for (int i = 1; i <= v; i++) {
		for (int n : graph[i])
			t_graph[n].push_back(i);
	}

	return t_graph;
}

int main() {
	cin >> v >> e;
	graph = vector<vector<int>>(v + 1);
	visited = vector<bool>(v + 1);
	scc = vector<int>(v + 1);

	for (int i = 0; i < e; i++) {
		int s, e; cin >> s >> e;
		graph[s].push_back(e);
	}

	t_graph = get_transpose();

	for (int i = 1; i <= v; i++) {
		if (visited[i])
			continue;

		visited[i] = true;
		dfs(i);
		s.push(i);
	}

	setup();

	while (!s.empty()) {		
		int cur = s.top(); s.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;
		scc[cur] = cur;
		t_dfs(cur, cur);
	}

	vector<bool> is_printed(v + 1);

	int cnt = 0;

	for (int i = 1; i <= v; i++) {
		if (is_printed[i])
			continue;

		int leader = scc[i];
		cnt++;

		for (int j = i; j <= v; j++) {
			if (scc[j] == leader) {
				is_printed[j] = true;
			}
		}
	}

	is_printed = vector<bool>(v + 1, false);

	cout << cnt << '\n';

	for (int i = 1; i <= v; i++) {
		if (is_printed[i])
			continue;

		int leader = scc[i];

		for (int j = i; j <= v; j++) {
			if (scc[j] == leader) {
				cout << j << ' ';
				is_printed[j] = true;
			}
		}
		cout << "-1\n";
	}
}