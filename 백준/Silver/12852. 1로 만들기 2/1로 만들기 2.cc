#include <iostream>
#include <vector>
using namespace std;

int x;
vector<int> dp;
vector<int> prev_num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x;
	dp = vector<int>(x + 1);
	prev_num = vector<int>(x + 1);
	dp[1] = 0;
	prev_num[1] = 0;

	for (int i = 2; i <= x; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			if (min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) == dp[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				prev_num[i] = i - 1;
			}

			else if (min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) == dp[i / 2]) {
				dp[i] = dp[i / 2] + 1;
				prev_num[i] = i / 2;
			}

			else {
				dp[i] = dp[i / 3] + 1;
				prev_num[i] = i / 3;
			}
		}

		else if (i % 2 == 0 && i % 3 != 0) {
			if (min(dp[i - 1], dp[i / 2]) == dp[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				prev_num[i] = i - 1;
			}

			else {
				dp[i] = dp[i / 2] + 1;
				prev_num[i] = i / 2;
			}
		}

		else if (i % 2 != 0 && i % 3 == 0) {
			if (min(dp[i - 1], dp[i / 3]) == dp[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				prev_num[i] = i - 1;
			}

			else {
				dp[i] = dp[i / 3] + 1;
				prev_num[i] = i / 3;
			}
		}

		else {
			dp[i] = dp[i - 1] + 1;
			prev_num[i] = i - 1;
		}
	}


	cout << dp[x] << '\n';
	while (x) {
		cout << x << ' ';
		x = prev_num[x];
	}
}