#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][31][3];
int num[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++)
        cin >> num[i];

    for (int i = 1; i <= t; i++) {
        dp[i][0][1] = dp[i - 1][0][1] + (num[i] == 1 ? 1 : 0);

        for (int j = 1; j <= w; j++) {
            if (i < j) break;

            if (num[i] == 1) {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + 1;
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
            }

            else {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
            }
        }
    }

    int ans = 0;

    for (int j = 0; j <= w; j++)
        ans = max({ ans, dp[t][j][1], dp[t][j][2] });

    cout << ans;
}