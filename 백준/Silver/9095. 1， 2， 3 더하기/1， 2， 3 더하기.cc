#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(11);

int f(int n) {
	if (n == 1) {
		return dp[1] = 1;
	}
	if (n == 2) {
		return dp[2] = 2;
	}
	if (n == 3) {
		return dp[3] = 4;
	}
	dp[n] = f(n - 1) + f(n - 2) + f(n - 3);
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	f(10);
	while (T--) {
		int n; cin >> n;
		cout << f(n) << '\n';
	}
}