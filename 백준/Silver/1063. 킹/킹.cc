#include <iostream>
#include <tuple>
using namespace std;

bool in_range(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

bool accept(int x1, int y1, int x2, int y2) {
	return (in_range(x1, y1) && in_range(x2, y2));
}

void subtitue(int& x1, const int& nx1, int& y1, const int& ny1,
	int& x2, const int& nx2, int& y2, const int& ny2) {
	if (accept(nx1, ny1, nx2, ny2)) {
		x1 = nx1;
		y1 = ny1;
		x2 = nx2;
		y2 = ny2;
	}
}

pair<int, int> encode(string pos) {
	int x, y;
	x = 8 - (pos[1] - '0');
	y = pos[0] - 'A';

	return { x, y };
}

string decode(int x, int y) {
	string pos;

	pos += y + 'A';
	pos += (8 - (x - '0'));

	return pos;
}

void process(string cmd, int& x_king, int& y_king, int& x_stone, int& y_stone) {
	if (cmd == "R") {
		int nx_king = x_king;
		int ny_king = y_king + 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone;
			ny_stone = y_stone + 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}
		
		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "L") {
		int nx_king = x_king;
		int ny_king = y_king - 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone;
			ny_stone = y_stone - 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "B") {
		int nx_king = x_king + 1;
		int ny_king = y_king;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone + 1;
			ny_stone = y_stone;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "T") {
		int nx_king = x_king - 1;
		int ny_king = y_king;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone - 1;
			ny_stone = y_stone;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "RT") {
		int nx_king = x_king - 1;
		int ny_king = y_king + 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone - 1;
			ny_stone = y_stone + 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "LT") {
		int nx_king = x_king - 1;
		int ny_king = y_king - 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone - 1;
			ny_stone = y_stone - 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "RB") {
		int nx_king = x_king + 1;
		int ny_king = y_king + 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone + 1;
			ny_stone = y_stone + 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}

	else if (cmd == "LB") {
		int nx_king = x_king + 1;
		int ny_king = y_king - 1;
		int nx_stone, ny_stone;

		if (nx_king == x_stone && ny_king == y_stone) {
			nx_stone = x_stone + 1;
			ny_stone = y_stone - 1;
		}

		else {
			nx_stone = x_stone;
			ny_stone = y_stone;
		}

		subtitue(x_king, nx_king, y_king, ny_king,
			x_stone, nx_stone, y_stone, ny_stone);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string pos_king, pos_stone;
	int n;
	cin >> pos_king >> pos_stone >> n;

	int x_king, y_king, x_stone, y_stone;
	tie(x_king, y_king) = encode(pos_king);
	tie(x_stone, y_stone) = encode(pos_stone);

	for (int i = 0; i < n; i++) {
		string cmd; cin >> cmd;
		process(cmd, x_king, y_king, x_stone, y_stone);
	}

	pos_king = decode(x_king, y_king);
	pos_stone = decode(x_stone, y_stone);

	cout << pos_king << '\n' << pos_stone;
}