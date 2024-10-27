#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k; cin >> n >> k;
    queue<int> q;
    vector<int> v;

    for (int i = 1; i <= n; i++)
        q.push(i);

    int cnt = 0;

    while (!q.empty()) {
        cnt++;

        if (cnt != k) {
            q.push(q.front());
            q.pop();
        }

        else {
            v.push_back(q.front());
            q.pop();
            cnt = 0;
        }
    }

    cout << '<';

    for (int i = 0; i < n; i++) {
        cout << v[i];

        if (i != n - 1)
            cout << ", ";
    }

    cout << '>';
}