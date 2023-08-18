#include <iostream>
#include <vector>
#include <queue>
#define INF 200001
using namespace std;

int n;
int dist[20001];
vector<pair<int, int>> edge[20001];

void dijkstra(int start) {
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if (dist[cur] < curDist) {
            continue;
        }
        for (int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].second;
            int nextDist = edge[cur][i].first;

            if (curDist + nextDist < dist[next]) {
                dist[next] = curDist + nextDist;
                pq.push({ curDist + nextDist, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int E;
    cin >> n >> E;
    int start; cin >> start;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({ w, v });
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == 200001) {
            cout << "INF" << '\n';
            continue;
        }
        cout << dist[i] << '\n';
    }
}