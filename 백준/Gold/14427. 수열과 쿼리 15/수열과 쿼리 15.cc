#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
vector<pair<long long, int>> t;

void init(int node, int s, int e) {
	if (s == e)
		t[node] = { v[s], s };

	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);

		if (t[node * 2].first <= t[node * 2 + 1].first)
			t[node] = t[node * 2];

		else
			t[node] = t[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx, long long val) {
	if (idx < s || idx > e)
		return;

	if (s == e) {
		v[idx] = val;
		t[node].first = val;
		return;
	}

	update(node * 2, s, (s + e) / 2, idx, val);
	update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);

	if (t[node * 2].first <= t[node * 2 + 1].first)
		t[node] = t[node * 2];

	else
		t[node] = t[node * 2 + 1];
}

pair<int, int> query(int node, int s, int e, int l, int r) {
	if (r < s || l > e)
		return { 1000000001, -1 };

	if (l <= s && r >= e)
		return t[node];

	pair<int, int> lmin = query(node * 2, s, (s + e) / 2, l, r);
	pair<int, int> rmin = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

	if (lmin.first <= rmin.first)
		return lmin;

	else
		return rmin;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	v = vector<long long>(n);
	t = vector<pair<long long, int>>(4 * n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	init(1, 0, n - 1);

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int a; cin >> a;

		if (a == 1) {
			int b, c; cin >> b >> c;
			update(1, 0, n - 1, b - 1, c);
		}

		else {
			pair<int, int> ans = query(1, 0, n - 1, 0, n - 1);
			cout << ans.second + 1 << '\n';
		}
	}
}