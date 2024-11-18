#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> dp(v);

	for (int i = 1; i < n; i++)
		if (dp[i - 1] + v[i] > dp[i])
			dp[i] = dp[i - 1] + v[i];

	cout << *max_element(dp.begin(), dp.end());
}