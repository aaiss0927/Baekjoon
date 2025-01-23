#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int board[5][4];
	int score[5] = { 0, };

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			cin >> board[i][j];

	int max_value = 0;
	int max_idx = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			score[i] += board[i][j];

		if (score[i] > max_value) {
			max_value = score[i];
			max_idx = i;
		}
	}

	cout << max_idx + 1 << ' ' << max_value;
}