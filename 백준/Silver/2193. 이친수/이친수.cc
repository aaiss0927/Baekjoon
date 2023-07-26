#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> dp(91);

long long f(int n) {
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	cout << f(N);
}