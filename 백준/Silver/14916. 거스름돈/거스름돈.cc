#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int coin[2] = { 2, 5 };
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
        dp[i] = -1;
    
    for (int i = 1; i <= n; i++) {
        int min = INT_MAX;

        for (int j = 0; j < 2; j++) {
            if (i >= coin[j] && dp[i - coin[j]] != -1 && dp[i - coin[j]] < min)
                min = dp[i - coin[j]];
        }

        if (min != INT_MAX)
            dp[i] = min + 1;
    }

    cout << dp[n];
}