#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> check_row(9, vector<bool>(9, false));
vector<vector<bool>> check_col(9, vector<bool>(9, false));
vector<vector<bool>> check_box(9, vector<bool>(9, false));

bool check(int row, int col, int num) {
	if (check_row[row][num - 1]) {
		return false;
	}
	if (check_col[col][num - 1]) {
		return false;
	}
	if (check_box[(row / 3) * 3 + (col / 3)][num - 1]) {
		return false;
	}
	return true;
}

void process(int idx, vector<pair<int, int>>& zero, vector<vector<int>>& board) {
	if (idx == zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		zero.clear();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (check(zero[idx].first, zero[idx].second, i)) {
			board[zero[idx].first][zero[idx].second] = i;
			check_row[zero[idx].first][i - 1] = true;
			check_col[zero[idx].second][i - 1] = true;
			check_box[(zero[idx].first / 3) * 3 + (zero[idx].second / 3)][i - 1] = true;
			process(idx + 1, zero, board);
			if (zero.size() == 0) {
				return;
			}
			board[zero[idx].first][zero[idx].second] = 0;
			check_row[zero[idx].first][i - 1] = false;
			check_col[zero[idx].second][i - 1] = false;
			check_box[(zero[idx].first / 3) * 3 + (zero[idx].second / 3)][i - 1] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board(9, vector<int>(9));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int x; cin >> x;

			board[i][j] = x;

			if (x == 0) {
				continue;
			}
			check_row[i][x - 1] = true;
			check_col[j][x - 1] = true;
			check_box[(i / 3) * 3 + (j / 3)][x - 1] = true;
		}
	}

	vector<pair<int, int>> zero;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				zero.emplace_back(i, j);
			}
		}
	}

	process(0, zero, board);
}