#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N);
	vector<int> a(N);
	
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v[i] = x;
	}

	stack<int> s;

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= v[i]) {
			s.pop();
		}

		if (s.empty()) {
			a[i] = -1;
		}

		else {
			a[i] = s.top();
		}

		s.push(v[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
}