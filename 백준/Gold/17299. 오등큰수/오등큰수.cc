#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int* count = new int[1000001];
	for (int i = 0; i < 1000001; i++) {
		count[i] = 0;
	}
	

	int N; cin >> N;
	vector<pair<int, int>> m;
	vector<int> a(N);
	vector<int> v;
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < N; i++) {
		count[v[i]]++;
	}

	for (int i = 0; i < N; i++) {
		m.push_back(make_pair(count[v[i]], v[i]));
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top().first <= m[i].first) {
			s.pop();
		}

		if (s.empty()) {
			a[i] = -1;
		}

		else {
			a[i] = s.top().second;
		}

		s.push(m[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
}