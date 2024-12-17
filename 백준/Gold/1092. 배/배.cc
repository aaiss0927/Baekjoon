#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> crane(n);

    for (int i = 0; i < n; i++)
        cin >> crane[i];

    int m;
    cin >> m;
    vector<int> box(m);

    for (int i = 0; i < m; i++)
        cin >> box[i];

    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());

    if (crane[0] < box[0]) {
        cout << -1;
        return 0;
    }

    int result = 0;
    vector<bool> visited(m);
    int cnt = 0;

    while (cnt < m) {
        int idx = 0;
        for (int i = 0; i < n; i++) {
            while (idx < m && (visited[idx] || crane[i] < box[idx]))
                idx++;
            if (idx < m) {
                visited[idx] = true;
                cnt++;
            }
        }
        result++;
    }

    cout << result;
}
