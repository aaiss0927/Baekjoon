#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> glass(n);

	for (int i = 0; i < n; i++)
		cin >> glass[i];

	dp[0][1] = glass[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i - 2; j++)
			dp[i][1] = max({dp[i][1], dp[j][1], dp[j][2]});
				
		dp[i][1] = glass[i] + dp[i][1];
		dp[i][2] = glass[i] + dp[i - 1][1];
	}

	int ans = -1;

	for (int i = 0; i < n; i++)
		ans = max({ans, dp[i][1], dp[i][2]});

	cout << ans;
}