#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> p;
vector<vector<int>> dp;

int main() {
	cin >> n;
	p = vector<int>(n + 1);
	dp = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		cin >> p[i] >> p[i + 1];
	}

	for (int k = 1; k <= n - 1; k++) {
		for (int i = 0; i <= n - 1 - k; i++) {
			int j = i + k;

			if (j == i + 1) {
				dp[i][j] = p[i] * p[i + 1] * p[i + 2];
			}

			else {
				int min = INT_MAX;

				for (int l = 0; l <= j - i - 1; l++) {
					int cur = dp[i][i + l] + dp[i + l + 1][j] + p[i] * p[i + l + 1] * p[j + 1];
					if (cur < min)
						min = cur;
				}

				dp[i][j] = min;
			}
		}
	}

	cout << dp[0][n - 1];
}