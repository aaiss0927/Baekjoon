#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k; j++)
			if (j - coin[i] >= 0)
				dp[j] += dp[j - coin[i]];

	cout << dp[k];
}