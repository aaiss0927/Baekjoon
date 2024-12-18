#include <iostream>
using namespace std;

int n, m;
int grid[1000][1000];
int dp[1000][1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++)
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + grid[i][j];
    }

    cout << dp[n - 1][m - 1];
}