#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num;
vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	num = vector<int>(n + 1);
	dp = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++) {
		dp[i] += dp[i - 1] + num[i];
	}

	while (m--) {
		int s, e; cin >> s >> e;
		cout << dp[e] - dp[s - 1] << '\n';
	}
}