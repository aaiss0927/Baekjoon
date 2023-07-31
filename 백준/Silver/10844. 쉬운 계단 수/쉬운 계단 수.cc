#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<vector<long>> dp(N + 1, vector<long>(10));

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	if (N >= 2) {
		dp[2][0] = 1;

		for (int i = 2; i <= N; i++) {
			if (i >= 3) {
				dp[i][0] = ((dp[i - 2][0] % 1000000000) + (dp[i - 2][2] % 1000000000)) % 1000000000;
			}
			for (int j = 1; j <= 8; j++) {
				dp[i][j] = ((dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000)) % 1000000000;
			}
			dp[i][9] = dp[i - 1][8] % 1000000000;
		}
	}

	long result = 0;
	for (int i = 1; i <= 9; i++) {
		result += dp[N][i];
		result %= 1000000000;
	}
	cout << result;
}