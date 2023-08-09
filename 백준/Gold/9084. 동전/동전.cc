#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int n, k;
		cin >> n;

		vector<int> coin(n);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		sort(coin.begin(), coin.end());

		cin >> k;

		vector<vector<int>> dp(k + 1, vector<int>(coin.size()));
		for (int i = 0; i < coin.size(); i++) {
			dp[0][i] = 1;
			for (int j = 1; j < coin.front(); j++) {
				dp[j][i] = 0;
			}
		}
		for (int i = coin.front(); i <= k; i++) {
			if (i - coin[0] >= 0) {
				dp[i][0] = dp[i - coin[0]][0];
			}
			for (int j = 1; j < coin.size(); j++) {
				dp[i][j] += dp[i][j - 1];
				if (i - coin[j] >= 0) {
					dp[i][j] += dp[i - coin[j]][j];
				}
			}
		}

		cout << dp[k][coin.size() - 1] << '\n';
	}
}