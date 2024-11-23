#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool dp[1001];

void solve(int cur, bool flag) {
	if (cur < 1)
		return;

	if (flag) {
		dp[cur - 2] = true;
		solve(cur - 2, !flag);
	}

	else {
		dp[cur - 5] = true;
		solve(cur - 5, !flag);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	if (n == 1 || n == 3 || n == 4) {
		cout << "SK";
		return 0;
	}

	if (n == 2) {
		cout << "CY";
		return 0;
	}

	dp[n] = true;
	solve(n, true);
	
	if (dp[1] || dp[3] || dp[4])
		cout << "SK";
	else
		cout << "CY";
}