#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    vector<int> lis;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    lis.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        if (lis.back() < v[i])
            lis.push_back(v[i]);

        else {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }

    cout << lis.size();
}