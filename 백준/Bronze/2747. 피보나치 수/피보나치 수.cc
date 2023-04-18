#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int k) {
	pair<int, int> p;
	if (k == 1) {
		p = make_pair(k, 0);
		return p;
	}
	p = f(k - 1);
	p = make_pair(p.first + p.second, p.first);
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cout << f(n).first;
}