#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

int main() {
	int T; cin >> T;

	dp = vector<int>(11);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}