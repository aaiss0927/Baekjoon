#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int grid[20][20];
tuple<int, int, int, int, int, int> dice;
//     위  아래  앞   뒤   왼    오

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

bool in_range(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void roll(int dir) {
	int ceil, floor, front, back, left, right;
	ceil = get<0>(dice);
	floor = get<1>(dice);
	front = get<2>(dice);
	back = get<3>(dice);
	left = get<4>(dice);
	right = get<5>(dice);

	if (dir == 1) {
		int temp = right;
		right = ceil;
		ceil = left;
		left = floor;
		floor = temp;
	}

	else if (dir == 2) {
		int temp = left;
		left = ceil;
		ceil = right;
		right = floor;
		floor = temp;
	}

	else if (dir == 3) {
		int temp = front;
		front = floor;
		floor = back;
		back = ceil;
		ceil = temp;
	}

	else if (dir == 4) {
		int temp = back;
		back = floor;
		floor = front;
		front = ceil;
		ceil = temp;
	}

	dice = { ceil, floor, front, back, left, right };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dice = { 0, 0, 0, 0, 0, 0 };
	int x, y, K; cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	while (K--) {
		int dir; cin >> dir;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!in_range(nx, ny))
			continue;

		x = nx; y = ny;
		roll(dir);

		int floor = get<1>(dice);

		if (grid[x][y] == 0) {
			grid[x][y] = floor;
		}

		else {
			dice = { get<0>(dice), grid[x][y], get<2>(dice), get<3>(dice), get<4>(dice), get<5>(dice) };
			grid[x][y] = 0;
		}

		cout << get<0>(dice) << '\n';
	}
}