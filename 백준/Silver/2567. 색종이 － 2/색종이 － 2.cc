#include <iostream>
using namespace std;

bool grid[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(const int& x, const int& y) {
	return(x >= 0 && x < 100 && y >= 0 && y < 100);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n; cin >> n;
	int len = 0;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++)
				grid[i][j] = true;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (grid[i][j] == true) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!grid[nx][ny] || !in_range(nx, ny)) len++;
				}
			}
		}
	}

	cout << len;
}