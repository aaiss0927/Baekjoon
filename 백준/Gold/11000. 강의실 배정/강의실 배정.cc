#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v[i] = { s, e };
    }

    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= pq.top())
            pq.pop();
        
        pq.push(v[i].second);
    }

    cout << pq.size();
}