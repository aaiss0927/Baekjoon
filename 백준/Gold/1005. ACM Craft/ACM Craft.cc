#include <iostream>
#include <vector>
using namespace std;

int solve(int target, vector<int>& A, vector<int>& T, vector<vector<int>>& graph, vector<int>& visited) {
	int maxi = 0;

	for (auto next : graph[target]) {
		if (!visited[next]) {
			A[next] = solve(next, A, T, graph, visited);
			visited[next] = true;
		}

		if (A[next] > maxi)
			maxi = A[next];
	}

	A[target] = maxi + T[target];
	return A[target];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC; cin >> TC;

	while (TC--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> graph(n + 1);
		vector<int> T(n + 1);
		vector<int> A(n + 1);
		vector<int> visited(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> T[i];
			A[i] = T[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			graph[y].push_back(x);
		}

		int target; cin >> target;
		cout << solve(target, A, T, graph, visited) << '\n';
	}
}