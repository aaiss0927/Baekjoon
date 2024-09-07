#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define INF 5000001
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
long long dist[501];

bool BF(int s) {
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int from, to, cost;
            tie(from, to, cost) = edges[j];

            if (dist[from] == INF)
                continue;

            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;

                if (i == n - 1)
                    return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    fill(dist, dist + 501, INF);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost; cin >> from >> to >> cost;
        edges.push_back({ from, to, cost });
    }

    if (!BF(1)) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF)
            cout << -1 << '\n';

        else
            cout << dist[i] << '\n';
    }
}