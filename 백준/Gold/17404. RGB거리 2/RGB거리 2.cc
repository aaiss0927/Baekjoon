#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 1000001

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> cost(n, vector<int>(3));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	int result = INT_MAX;

	for (int first = 0; first <= 2; first++) {
		vector<vector<int>> dp(n, vector<int>(3));

		for (int i = 0; i < 3; i++) {
			if (i == first)
				dp[0][i] = cost[0][i];
			else
				dp[0][i] = INT_MAX;
		}

		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++) {
			if (i == first)
				continue;

			else
				result = min(result, dp[n - 1][i]);
		}
	}
	cout << result;
}