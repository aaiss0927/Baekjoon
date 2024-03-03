#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

pair<int, int> add_time(pair<int, int> p1, pair<int, int> p2) {
	int m, s;
	int carry = 0;

	if (p1.second + p2.second >= 60) {
		s = p1.second + p2.second - 60;
		carry = 1;
	}

	else {
		s = p1.second + p2.second;
	}

	m = p1.first + p2.first + carry;

	return { m, s };
}

pair<int, int> sub_time(pair<int, int> p1, pair<int, int> p2) {
	int m, s;
	int carry = 0;

	if (p1.second < p2.second) {
		s = p1.second - p2.second + 60;
		carry = 1;
	}

	else {
		s = p1.second - p2.second;
	}

	m = p1.first - p2.first - carry;

	return { m, s };
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int t1_score, t2_score;
	t1_score = t2_score = 0;
	bool is_t1_win = false;
	bool is_t2_win = false;
	pair<int, int> t1_win_start_time;
	pair<int, int> t1_win_end_time;
	pair<int, int> t2_win_start_time;
	pair<int, int> t2_win_end_time;
	pair<int, int> t1_win_time = { 0, 0 };
	pair<int, int> t2_win_time = { 0, 0 };

	while (n--) {
		int team;
		string time;
		cin >> team >> time;

		pair<int, int> time_ = { stoi(time.substr(0, 2)), stoi(time.substr(3, 5)) };

		if (team == 1) {
			t1_score++;
		}

		else {
			t2_score++;
		}

		if (!is_t1_win && t1_score > t2_score) {
			is_t1_win = true;
			t1_win_start_time = time_;

		}

		else if (!is_t2_win && t1_score < t2_score) {
			is_t2_win = true;
			t2_win_start_time = time_;
		}

		else if (is_t1_win && t1_score <= t2_score) {
			is_t1_win = false;
			t1_win_end_time = time_;
			t1_win_time = add_time(t1_win_time, sub_time(t1_win_end_time, t1_win_start_time));
		}

		else if (is_t2_win && t1_score >= t2_score) {
			is_t2_win = false;
			t2_win_end_time = time_;
			t2_win_time = add_time(t2_win_time, sub_time(t2_win_end_time, t2_win_start_time));
		}
	}

	if (is_t1_win) {
		t1_win_end_time = {48, 0};
		t1_win_time = add_time(t1_win_time, sub_time(t1_win_end_time, t1_win_start_time));
	}

	if (is_t2_win) {
		t2_win_end_time = { 48, 0 };
		t2_win_time = add_time(t2_win_time, sub_time(t2_win_end_time, t2_win_start_time));
	}

	cout << right << setfill('0');

	cout << setw(2) << t1_win_time.first;
	cout << ':';
	cout << setw(2) << t1_win_time.second;
	cout << '\n';
	cout << setw(2) << t2_win_time.first;
	cout << ':';
	cout << setw(2) << t2_win_time.second;
}