#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(16, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v;
	v.emplace_back(0, 0);
	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		v.emplace_back(t, p);
	}

	for (int i = N; i >= 1; i--) {
		if (i + v[i].first > N + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], v[i].second + dp[i + v[i].first]);
		}
	}

	cout << dp[1];
}