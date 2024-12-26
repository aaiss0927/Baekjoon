#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<long long> v(n);
    vector<long long> lis;
    vector<int> idx_table(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    lis.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        if (v[i] > lis.back()) {
            idx_table[i] = lis.size();
            lis.push_back(v[i]);
        }

        else {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
            idx_table[i] = idx;
        }
    }

    vector<long long> result;
    int target = lis.size() - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (idx_table[i] == target) {
            result.push_back(v[i]);
            target--;
        }

        if (target < 0)
            break;
    }

    cout << lis.size() << '\n';

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
}