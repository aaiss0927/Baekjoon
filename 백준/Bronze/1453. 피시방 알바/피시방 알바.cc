#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(101);
	for (int i = 0; i <= 100; i++) {
		v[i] = 0;
	}

	int N; cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (v[x] == 0) {
			v[x] = 1;
		}
		else {
			count++;
		}
	}
	cout << count;
}