#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
vector<long long> t;

void init(int node, int s, int e) {
	if (s == e)
		t[node] = v[s];

	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);
		t[node] = t[node * 2] + t[node * 2 + 1];
	}
}

long long query(int node, int s, int e, int l, int r) {
	if (r < s || l > e)
		return 0;

	if (l <= s && r >= e)
		return t[node];

	long long lsum = query(node * 2, s, (s + e) / 2, l, r);
	long long rsum = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

	return lsum + rsum;
}

void update(int node, int s, int e, int idx, long long val) {
	if (idx < s || idx > e)
		return;

	if (s == e) {
		v[idx] = val;
		t[node] = val;
		return;
	}

	update(node * 2, s, (s + e) / 2, idx, val);
	update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
	t[node] = t[node * 2] + t[node * 2 + 1];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	v = vector<long long>(n, 0);
	t = vector<long long>(4 * n);

	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		long long a, b, c; cin >> a >> b >> c;

		if (a == 1)
			update(1, 0, n - 1, b - 1, c);

		else {
			if (b > c)
				swap(b, c);

			cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
		}	
	}
}