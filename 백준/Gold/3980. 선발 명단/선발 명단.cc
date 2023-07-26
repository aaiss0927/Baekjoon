#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool>> cpt;
vector<bool> check_col;
int M;

void process(int row, int& sum, vector<vector<int>>& table) {
	if (row == 11) {
		if (sum > M) {
			M = sum;
		}
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!cpt[row][i] || check_col[i]) {
			continue;
		}
		else {
			sum += table[row][i];
			check_col[i] = true;
			process(row + 1, sum, table);
			check_col[i] = false;
			sum -= table[row][i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	int T; cin >> T;
	while (T--) {
		vector<vector<int>> table(11, vector<int>(11));
		cpt = vector<vector<bool>>(11, vector<bool>(11, false));
		check_col = vector<bool>(11, false);
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> table[i][j];
				if (table[i][j] != 0) {
					cpt[i][j] = true;
				}
			}
		}
		M = 0;
		int sum = 0;
		process(0, sum, table);
		cout << M << '\n';
	}
}