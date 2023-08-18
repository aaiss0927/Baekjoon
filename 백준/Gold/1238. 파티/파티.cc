#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999
using namespace std;

long long dist[1001][1001];
long long result[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] == 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        result[i] = dist[i][X] + dist[X][i];
    }

    sort(result, result + 1001);
    cout << result[1000];
}