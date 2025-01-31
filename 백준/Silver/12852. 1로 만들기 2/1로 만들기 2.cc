#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[1000001];
int prev_num[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x; cin >> x;
    
    for (int i = 1; i <= x; i++)
        dp[i] = INT_MAX;

    dp[x] = 0;

    for (int i = x; i > 1; i--) {
        if (i % 3 == 0) {
            if (dp[i] + 1 < dp[i / 3]) {
                dp[i / 3] = dp[i] + 1;
                prev_num[i / 3] = i;
            }
        }

        if (i % 2 == 0) {
            if (dp[i] + 1 < dp[i / 2]) {
                dp[i / 2] = dp[i] + 1;
                prev_num[i / 2] = i;
            }
        }

        if (dp[i] + 1 < dp[i - 1]) {
            dp[i - 1] = dp[i] + 1;
            prev_num[i - 1] = i;
        }
    }

    cout << dp[1] << '\n';
    int cur = 1;
    vector<int> v = { 1 };

    while (cur != x) {
        cur = prev_num[cur];
        v.push_back(cur);
    }

    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << ' ';
}