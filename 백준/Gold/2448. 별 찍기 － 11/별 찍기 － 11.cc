#include <iostream>
using namespace std;

char grid[3100][6200];

void solve(int n, int r, int c) {
	if (n == 3) {
		grid[r][c] = '*';
		grid[r + 1][c - 1] = '*';
		grid[r + 1][c + 1] = '*';

		for (int i = c - 2; i <= c + 2; i++) {
			grid[r + 2][i] = '*';
		}

		return;
	}

	int side = n / 2;

	solve(side, r, c);
	solve(side, r + side, c - side);
	solve(side, r + side, c + side);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			grid[i][j] = ' ';
		}
	}

	solve(n, 0, n - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
}