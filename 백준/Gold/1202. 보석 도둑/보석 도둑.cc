#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    vector<pair<int, int>> gem(n);
    multiset<int> bag;

    for (int i = 0; i < n; i++)
        cin >> gem[i].second >> gem[i].first;

    for (int i = 0; i < k; i++) {
        int c; cin >> c;
        bag.insert(c);
    }

    sort(gem.rbegin(), gem.rend());

    long long total = 0;

    for (int i = 0; i < n; i++) {
        auto it = bag.lower_bound(gem[i].second);

        if (it != bag.end()) {
            total += gem[i].first;
            bag.erase(it);
        }
    }

    cout << total;
}