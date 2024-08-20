#include <iostream>
using namespace std;

int dp[41];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	while (T--) {
		int n; cin >> n;

		if (n == 0)
			cout << "1 0\n";

		else
			cout << dp[n - 1] << ' ' << dp[n] << '\n';
	}
}