#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<char>> result(m, vector<char>(n));

	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int j = 0; j < m; j++)
			grid[i][j] = str[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][i] = grid[i][m - j - 1];

			if (result[j][i] == '.')
				result[j][i] = '.';

			else if (result[j][i] == 'O')
				result[j][i] = 'O';

			else if (result[j][i] == '-')
				result[j][i] = '|';

			else if (result[j][i] == '|')
				result[j][i] = '-';

			else if (result[j][i] == '/')
				result[j][i] = '\\';

			else if (result[j][i] == '\\')
				result[j][i] = '/';

			else if (result[j][i] == '^')
				result[j][i] = '<';

			else if (result[j][i] == '<')
				result[j][i] = 'v';

			else if (result[j][i] == 'v')
				result[j][i] = '>';

			else if (result[j][i] == '>')
				result[j][i] = '^';
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << result[i][j];
		cout << '\n';
	}
}