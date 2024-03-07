#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[10001];
bool visited[10001];
int temp[10001];
int cnt;
int ans;

void setup() {
	cnt = 1;

	for (int i = 0; i < 10001; i++) {
		visited[i] = false;
	}
}

void dfs(int num) {
	for (int i = 0; i < graph[num].size(); i++) {
		if (!visited[graph[num][i]]) {
			cnt++;
			visited[graph[num][i]] = true;
			dfs(graph[num][i]);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	while (m--) {
		int first, second; cin >> first >> second;

		graph[second].push_back(first);
	}

	ans = 0;

	for (int i = 1; i <= n; i++) {
		setup();
		visited[i] = true;
		dfs(i);
		temp[i] = cnt;

		ans = max(ans, cnt);
	}

	for (int i = 1; i <= n; i++) {
		if (temp[i] == ans) {
			cout << i << ' ';
		}
	}
}