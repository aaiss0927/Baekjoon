#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1501
using namespace std;

int dist[101][101];
int item[101];
int result[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        dist[a][b] = l;
        dist[b][a] = l;
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
            if (dist[i][j] <= m) {
                result[i] += item[j];
            }
        }
    }

    sort(result, result + 101);
    cout << result[100];
}