#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll dp[1500002];
pair<int, ll> v[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, p; cin >> t >> p;
        v[i] = { t, p };
    }

    ll max_cost = 0;

    for (int i = 1; i <= n + 1; i++) {
        dp[i] = max_cost = max(max_cost, dp[i]);

        if (i + v[i].first > n + 1)
            continue;

        dp[i + v[i].first] = max(dp[i] + v[i].second, dp[i + v[i].first]);
    }

    cout << *max_element(dp, dp + (n + 2));
}