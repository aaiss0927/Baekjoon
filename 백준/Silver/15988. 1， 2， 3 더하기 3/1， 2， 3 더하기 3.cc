#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int n; cin >> n;
		vector<long long> dp(n + 1);

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			dp[i] %= 1000000009;
		}

		cout << dp[n] << '\n';
	}
}