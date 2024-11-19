#include <iostream>
#include <vector>
using namespace std;

int dp[1001][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	k = (n - k < k) ? (n - k) : k;

	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;

	cout << dp[n][k];
}