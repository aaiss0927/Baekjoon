#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int cur = v[n - 1];
    int cnt = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > cur) {
            cur = v[i];
            cnt++;
        }
    }

    cout << cnt;
}