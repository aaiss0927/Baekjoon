#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(10000001);
int cnt;

int op(int x) {
	for (int i = 2; i <= x; i++) {
		if (i % 6 == 0) {
			dp[i] = min(dp[i / 3], dp[i / 2]) + 1;
		}
		else if (i % 6 == 1) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (i % 6 == 2) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else if (i % 6 == 3) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 6 == 4) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else if (i % 6 == 5) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x; cin >> x;
	dp[1] = 0;
	cout << op(x);
}