#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector <vector<char>> grid(n, vector<char>(n));
	vector <vector<char>> result(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int j = 0; j < n; j++)
			grid[i][j] = str[j];
	}

	int cmd; cin >> cmd;

	if (cmd == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				result[i][j] = grid[i][j];
	}

	else if (cmd == 2) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				result[i][j] = grid[i][n - j - 1];
	}

	else if (cmd == 3) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				result[i][j] = grid[n - i - 1][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << result[i][j];
		cout << '\n';
	}
}