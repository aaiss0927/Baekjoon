#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[51];
bool visited[51];
int cnt;

void dfs(int num, int del_num) {
	int del_idx = -1;

	for (int i = 0; i < graph[num].size(); i++) {
		if (!visited[graph[num][i]]) {
			if (graph[num][i] == del_num) {
				del_idx = i;
				continue;
			}

			visited[graph[num][i]] = true;
			dfs(graph[num][i], del_num);
		}
	}

	if (del_idx != -1) {
		graph[num].erase(graph[num].begin() + del_idx);
	}

	if (graph[num].empty()) {
		cnt++;
		return;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int root;

	for (int i = 0; i < n; i++) {
		int par_num; cin >> par_num;

		if (par_num == -1) {
			root = i;
			continue;
		}

		graph[par_num].push_back(i);
	}

	int del_num; cin >> del_num;

	if (del_num == root) {
		cout << 0;
		return 0;
	}

	cnt = 0;
	visited[root] = true;
	dfs(root, del_num);
	cout << cnt;
}