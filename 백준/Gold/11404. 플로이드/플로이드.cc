#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

int dist[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dist[i][j] = INF;
        }
    }

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (dist[a][b] > c) {
            dist[a][b] = c;
        }
    }

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << '\n';
    }   
}