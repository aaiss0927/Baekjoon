#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	vector<bool> isUsed(n + 1, false);

	vector<int> dp(n + 1, 0);

	dp[1] = arr[1];
	if (n >= 2) {
		dp[2] = arr[1] + arr[2];
	}
	if (n >= 3) {
		dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	}
	
	if (n >= 4) {
		for (int i = 4; i <= n; i++) {
			dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		}
	}

	cout << dp[n];
}