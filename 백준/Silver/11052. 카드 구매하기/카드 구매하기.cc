#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<int> P(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	vector<int> dp(N + 1, 0);
	dp[1] = P[1];
	for (int i = 2; i <= N; i++) {
		int max = P[i];
		for (int j = 1; i - j >= j; j++) {
			if (dp[i - j] + dp[j] > max) {
				max = dp[i - j] + dp[j];
			}
		}
		dp[i] = max;
	}

	cout << dp[N];
}