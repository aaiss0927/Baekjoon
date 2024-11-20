#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (v[j] > v[i])
				dp[i] = max(dp[i], dp[j] + 1);

	cout << *max_element(dp.begin(), dp.end());
}