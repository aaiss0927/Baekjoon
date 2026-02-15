#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string board; cin >> board;
	string result = "";

	for (int i = 0; i < board.length();) {
		if (board[i] == '.') {
			result += '.';
			i++;
		}

		int cnt = 0;
		while (i < board.length() && board[i] == 'X') {
			cnt++;
			i++;
		}

		if (cnt % 2 == 1) {
			cout << -1;
			return 0;
		}

		while (cnt >= 4) {
			result += "AAAA";
			cnt -= 4;
		}

		if (cnt == 2) {
			result += "BB";
			cnt -= 2;
		}
	}

	cout << result;
}