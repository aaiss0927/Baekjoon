#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long a, b;
queue<pair<long long, int>> q;
bool is_printed = false;

void bfs() {
    while (!q.empty()) {
        pair<long long, int> cur = q.front();
        q.pop();

        if (cur.first == b) {
            cout << cur.second + 1;
            is_printed = true;
            return;
        }

        if (cur.first * 2 <= b)
            q.push({ cur.first * 2, cur.second + 1 });

        if (cur.first * 10 + 1 <= b) 
            q.push({ cur.first * 10 + 1, cur.second + 1 });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    q.push({a, 0});
    bfs();

    if (!is_printed)
        cout << -1;
}