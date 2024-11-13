#include <iostream>
#include <string>
using namespace std;

int arr[300][300];
int row_cumsum[300][300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int j = 0; j < m; j++)
		row_cumsum[0][j] = arr[0][j];

	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++)
			row_cumsum[i][j] = row_cumsum[i - 1][j] + arr[i][j];
	}

	int k; cin >> k;

	while (k--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		int result = 0;

		for (int i = b; i <= d; i++) {
			if (a >= 1)
				result += (row_cumsum[c][i] - row_cumsum[a - 1][i]);
			else
				result += row_cumsum[c][i];
		}
		
		cout << result << '\n';
	}
}