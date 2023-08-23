#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

int dist[801][801];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 801; i++) {
        for (int j = 0; j < 801; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
        dist[b][a] = c;
    }

    int v1, v2;
    cin >> v1 >> v2;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int min = INF;
    if (dist[1][v1] + dist[v1][v2] + dist[v2][n] >= INF && dist[1][v2] + dist[v2][v1] + dist[v1][n] >= INF) {
        cout << -1;
        return 0;
    }
    else {
        if (dist[1][v1] + dist[v1][v2] + dist[v2][n] < dist[1][v2] + dist[v2][v1] + dist[v1][n]) {
            min = dist[1][v1] + dist[v1][v2] + dist[v2][n];
        }
        else {
            min = dist[1][v2] + dist[v2][v1] + dist[v1][n];
        }
        
    }
    cout << min;
}