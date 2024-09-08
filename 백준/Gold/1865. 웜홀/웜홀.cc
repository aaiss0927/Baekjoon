#include <iostream>
#include <vector>
#include <tuple>
#define INF 25000001
using namespace std;

vector<tuple<int, int, int>> edges;
long long dist[501];

bool BF(int s, int num_vertex, int num_edge) {
	dist[s] = 0;

	for (int i = 0; i < num_vertex; i++) {
		for (int j = 0; j < num_edge; j++) {
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;

				if (i == num_vertex - 1)
					return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		edges.clear();
		fill(dist, dist + 501, INF);
		int n, m, w; cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			edges.push_back({ s, e, -t });
		}

		if (!BF(1, n, 2 * m + w))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}