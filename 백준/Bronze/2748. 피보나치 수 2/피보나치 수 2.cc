#include <iostream>
using namespace std;

int n;
long long dp[91];

int main() {
	int n; cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < 91; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}