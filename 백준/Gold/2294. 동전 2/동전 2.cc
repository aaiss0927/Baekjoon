#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i - coin[j] >= 0 && dp[i - coin[j]] != INT_MAX)
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);

	if (dp[k] == INT_MAX)
		cout << -1;
	else
		cout << dp[k];
}