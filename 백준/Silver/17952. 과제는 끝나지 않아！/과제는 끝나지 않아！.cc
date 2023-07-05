#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<pair<int, int>> S;
	int score = 0;

	int N; cin >> N;
	int state;
	int A, T;
	for (int i = 0; i < N; i++) {
		cin >> state;
		if (state == 1) {
			cin >> A >> T;
			S.push(make_pair(A, T));
		}
		if (!S.empty()) {
			S.top().second -= 1;
			if (S.top().second == 0) {
				score += S.top().first;
				S.pop();
			}
		}
	}

	cout << score;
}