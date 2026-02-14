#include <iostream>
using namespace std;

void preprocessing(int& dir) {
	if (dir == 3) dir = 2;
	else if (dir == 2) dir = 3;
}

bool check_clock_dir(int prev_dir, int dir) {
	if (prev_dir == 0)
		return false;

	if ((dir % 4) == prev_dir - 1)
		return false;

	else return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int k; cin >> k;
	int max_h = 0;
	int max_w = 0;
	int small_area = 0;
	int prev_dir = 0;
	int prev_len = 0;
	bool flag = false;
	int first_len = 0;

	for (int i = 0; i < 6; i++) {
		int dir, len; cin >> dir >> len;
		preprocessing(dir);
		
		if (i == 0) first_len = len;
		
		if (check_clock_dir(prev_dir, dir)) {
			flag = true;
			small_area = prev_len * len;
		}

		if (i == 5 && !flag) small_area = len * first_len;

		else {
			if (dir % 2 == 1 && len > max_w) max_w = len;
			else if (dir % 2 == 0 && len > max_h) max_h = len;
		}

		prev_dir = dir;
		prev_len = len;
	}

	cout << (max_h * max_w - small_area) * k;
}