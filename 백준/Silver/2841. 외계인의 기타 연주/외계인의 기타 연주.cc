#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, P;
	cin >> N >> P;
	stack<int> s[7];
	int count = 0;

	while (N--) {
		int l, f;
		cin >> l >> f;

		if (s[l].empty()) {
			s[l].push(f);
			count++;
		}
		else {
			while (f < s[l].top()) {
				s[l].pop();
				count++;
				if (s[l].empty()) {
					s[l].push(f);
					count++;
				}
			}
			if (f > s[l].top()) {
				s[l].push(f);
				count++;
			}
		}
	}
	cout << count;
}