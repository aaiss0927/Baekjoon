#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int cnt = 0;
vector<bool> check_col;
vector<bool> check_lr;
vector<bool> check_rl;

bool check(int row, int col) {
	if (check_col[col]) {
		return false;
	}
	if (check_lr[row - col + N - 1]) {
		return false;
	}
	if (check_rl[row + col]) {
		return false;
	}
	return true;
}

void process(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check(row, i)) {
			continue;
		}
		else {
			check_col[i] = true;
			check_lr[row - i + N - 1] = true;
			check_rl[row + i] = true;
			process(row + 1);
			check_col[i] = false;
			check_lr[row - i + N - 1] = false;
			check_rl[row + i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	check_col = vector<bool>(N, false);
	check_lr = vector<bool>(2 * N - 1, false);
	check_rl = vector<bool>(2 * N - 1, false);

	process(0);

	cout << cnt;
}