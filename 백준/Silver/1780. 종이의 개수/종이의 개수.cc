#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> grid;

int cnt_m1;
int cnt_0;
int cnt_p1;

bool is_equal(int s_r, int s_c, int e_r, int e_c) {
	int stand = grid[s_r][s_c];

	for (int i = s_r; i < e_r; i++) {
		for (int j = s_c; j < e_c; j++) {
			if (grid[i][j] != stand) {
				return false;
			}
		}
	}

	return true;
}

void althm(int n, int s_r, int s_c, int e_r, int e_c) {
	if (n == 1) {
		if (grid[s_r][s_c] == -1) {
			cnt_m1++;
		}

		else if (grid[s_r][s_c] == 0) {
			cnt_0++;
		}

		else if (grid[s_r][s_c] == 1) {
			cnt_p1++;
		}

		return;
	}

	if (is_equal(s_r, s_c, e_r, e_c)) {
		if (grid[s_r][s_c] == -1) {
			cnt_m1++;
		}

		else if (grid[s_r][s_c] == 0) {
			cnt_0++;
		}

		else if (grid[s_r][s_c] == 1) {
			cnt_p1++;
		}
		
		return;
	}

	int r_sect_1 = s_r;
	int r_sect_2 = s_r + (e_r - s_r) / 3;
	int r_sect_3 = s_r + (e_r - s_r) / 3 * 2;
	int r_sect_4 = e_r;

	int c_sect_1 = s_c;
	int c_sect_2 = s_c + (e_c - s_c) / 3;
	int c_sect_3 = s_c + (e_c - s_c) / 3 * 2;
	int c_sect_4 = e_c;

	althm(n / 3, r_sect_1, c_sect_1, r_sect_2, c_sect_2);
	althm(n / 3, r_sect_1, c_sect_2, r_sect_2, c_sect_3);
	althm(n / 3, r_sect_1, c_sect_3, r_sect_2, c_sect_4);

	althm(n / 3, r_sect_2, c_sect_1, r_sect_3, c_sect_2);
	althm(n / 3, r_sect_2, c_sect_2, r_sect_3, c_sect_3);
	althm(n / 3, r_sect_2, c_sect_3, r_sect_3,  c_sect_4);

	althm(n / 3, r_sect_3, c_sect_1, r_sect_4,  c_sect_2);
	althm(n / 3, r_sect_3, c_sect_2, r_sect_4,  c_sect_3);
	althm(n / 3, r_sect_3, c_sect_3, r_sect_4,  c_sect_4);
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

	althm(n, 0, 0, n, n);
	cout << cnt_m1 << '\n' << cnt_0 << '\n' << cnt_p1;
}