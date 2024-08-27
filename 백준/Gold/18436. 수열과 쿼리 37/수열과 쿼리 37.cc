#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<pair<int, int>> t;

void init(int node, int s, int e) {
	if (s == e) {
		if (v[s] % 2 == 0)
			t[node] = { 1, 0 };

		else
			t[node] = { 0, 1 };
	}

	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);

		pair<int, int> left = t[node * 2];
		pair<int, int> right = t[node * 2 + 1];
		t[node] = { left.first + right.first, left.second + right.second };
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (idx < s || idx > e)
		return;

	if (s == e) {
		v[idx] = val;

		if (val % 2 == 0)
			t[node] = { 1, 0 };

		else
			t[node] = { 0, 1 };

		return;
	}

	update(node * 2, s, (s + e) / 2, idx, val);
	update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);

	pair<int, int> left = t[node * 2];
	pair<int, int> right = t[node * 2 + 1];
	t[node] = { left.first + right.first, left.second + right.second };
}

pair<long long, long long> query(int node, int s, int e, int l, int r) {
	if (r < s || l > e)
		return { 0, 0 };

	if (l <= s && r >= e)
		return t[node];

	pair<int, int> lcnts = query(node * 2, s, (s + e) / 2, l, r);
	pair<int, int> rcnts = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

	return { lcnts.first + rcnts.first, lcnts.second + rcnts.second };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	v = vector<int>(n);
	t = vector<pair<int, int>>(4 * n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	init(1, 0, n - 1);

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;

		if (a == 1)
			update(1, 0, n - 1, b - 1, c);
		
		else if (a == 2)
			cout << query(1, 0, n - 1, b - 1, c - 1).first << '\n';

		else
			cout << query(1, 0, n - 1, b - 1, c - 1).second << '\n';
	}
}