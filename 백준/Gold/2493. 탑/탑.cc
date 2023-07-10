#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> m;
	vector<int> a;
	stack<pair<int, int>> s;
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		m.insert(make_pair(i, h));
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		while (!s.empty() && s.top().second <= it->second) {
			s.pop();
		}

		if (s.empty()) {
			a.push_back(0);
		}

		else {
			a.push_back(s.top().first + 1);
		}

		s.push(*it);
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
}