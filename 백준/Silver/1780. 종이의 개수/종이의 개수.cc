#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
int cnt[3];

bool is_equal(int n, int r, int c) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (grid[i][j] != grid[r][c]) {
				return false;
			}
		}
	}

	return true;
}

void count_paper(int n, int r, int c) {
	if (is_equal(n, r, c)) {
		cnt[grid[r][c] + 1]++;
		return;
	}

	int side = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			count_paper(n / 3, r + i * side, c + j * side);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	grid = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	count_paper(n, 0, 0);
	
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
}