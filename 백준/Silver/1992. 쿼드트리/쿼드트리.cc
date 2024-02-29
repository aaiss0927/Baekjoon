#include <iostream>
#include <cmath>
using namespace std;

int n;
int grid[64][64];
string ans = "";

void quad_tree(int size, int s_r, int e_r, int s_c, int e_c) {
	int cnt = 0;

	for (int i = s_r; i < e_r; i++) {
		for (int j = s_c; j < e_c; j++) {
			if (grid[i][j] == 0) {
				cnt++;
			}
		}
	}

	if (cnt == 0) {
		ans += "1";
		return;
	}

	else if (cnt == pow(size, 2)) {
		ans += "0";
		return;
	}

	else {
		ans += "(";
		quad_tree(size / 2, s_r, (s_r + e_r) / 2, s_c, (s_c + e_c) / 2);
		quad_tree(size / 2, s_r, (s_r + e_r) / 2, (s_c + e_c) / 2, e_c);
		quad_tree(size / 2, (s_r + e_r) / 2, e_r, s_c, (s_c + e_c) / 2);
		quad_tree(size / 2, (s_r + e_r) / 2, e_r, (s_c + e_c) / 2, e_c);
		ans += ")";
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		for (int j = 0; j < n; j++) {
			grid[i][j] = s[j] - '0';
		}
	}

	quad_tree(n, 0, n, 0, n);

	cout << ans;
}