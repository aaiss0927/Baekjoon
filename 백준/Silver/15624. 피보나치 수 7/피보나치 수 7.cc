#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	if (n <= 1) {
		cout << n;
		return 0;
	}

	vector<long long> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

	cout << dp[n];
}