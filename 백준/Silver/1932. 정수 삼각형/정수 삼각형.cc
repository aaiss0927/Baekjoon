#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> tri(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int x; cin >> x;
			tri[i].push_back(x);
		}
	}

	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i].push_back(0);
		}
	}
	dp[0][0] = tri[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + tri[i][j];
				continue;
			}
			if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
	}

	sort(dp[n - 1].begin(), dp[n - 1].end());
	cout << dp[n - 1].back();
}