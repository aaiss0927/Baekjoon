#include <iostream>
using namespace std;

int h, w;
char grid[100][100];
int ans[100][100];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string str; cin >> str;

		for (int j = 0; j < w; j++) {
			grid[i][j] = str[j];
			ans[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		bool is_cloud = false;
		int t = 0;

		for (int j = 0; j < w; j++) {
			if (grid[i][j] == 'c') {
				is_cloud = true;
				t = 0;
			}

			if (is_cloud) {
				ans[i][j] = t;
			}

			t++;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}