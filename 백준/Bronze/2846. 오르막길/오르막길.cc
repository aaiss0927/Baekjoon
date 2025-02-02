#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);

    int maxi = 0;
    int head, tail;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int idx = 1;
    head = 0;

    while (idx < n) {
        if (v[idx - 1] < v[idx]) {
            idx++;
        }

        else {
            tail = idx - 1;
            maxi = max(maxi, v[tail] - v[head]);
            head = idx;
            idx++;
        }
    }

    tail = idx - 1;
    maxi = max(maxi, v[tail] - v[head]);

    cout << maxi;
}