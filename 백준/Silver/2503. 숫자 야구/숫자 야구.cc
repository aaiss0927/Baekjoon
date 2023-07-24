#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> logic(string query, string ans) {
	int dup = 0;
	int strk = 0;
	int ball;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (query[i] == ans[j]) {
				dup++;
				if (i == j) {
					strk++;
				}
			}
		}
	}
	ball = dup - strk;

	return make_pair(strk, ball);
}

void check(string num, int f, int s, bool* cand) {
	for (int i = 111; i <= 999; i++) {
		if (!cand[i]) {
			continue;
		}
		if (!(logic(num, to_string(i)).first == f && logic(num, to_string(i)).second == s)) {
			cand[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	bool cand[1000]{ false };
	for (int i = 111; i <= 999; i++) {
		cand[i] = true;
	}
	for (int i = 111; i <= 999; i++) {
		string s = to_string(i);
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
			cand[i] = false;
		}
		if (s[1] == '0' || s[2] == '0') {
			cand[i] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		string num;
		int x, y;
		cin >> num >> x >> y;

		check(num, x, y, cand);
	}

	int count = 0;
	for (int i = 111; i <= 999; i++) {
		if (cand[i]) {
			count++;
		}
	}

	cout << count;
}