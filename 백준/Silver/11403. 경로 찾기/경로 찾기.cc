#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

vector<int> graph[100];
vector<bool> visited;

void dfs(int x, vector<int>& v) {
	for (auto i : graph[x]) {
		if (!visited[i]) {
			v.push_back(i);
			visited[i] = true;
			dfs(i, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; cin >> x;
			if (x == 1) {
				graph[i].push_back(j);
			}
		}
	}

	vector<vector<int>> available(N);
	for (int i = 0; i < N; i++) {
		visited = vector<bool>(N, false);
		dfs(i, available[i]);
	}

	vector<vector<int>> result(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < available[i].size(); j++) {
			result[i][available[i][j]] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
}