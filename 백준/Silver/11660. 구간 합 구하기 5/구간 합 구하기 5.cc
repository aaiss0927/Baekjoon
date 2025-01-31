#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grid[1024][1024];
int dp[1024][1024];
// 열 방향으로 합 구하는 DP[n]
// dp[i][j] : i행에서, 0열부터 j열까지의 합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        dp[i][0] = grid[i][0];

    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i][j - 1] + grid[i][j];

    while (m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int ans = 0;

        for (int i = x1; i <= x2; i++) {
            if (y1 - 1 >= 0)
                ans += (dp[i][y2] - dp[i][y1 - 1]);

            else
                ans += dp[i][y2];
        }

        cout << ans << '\n';
    }    
}