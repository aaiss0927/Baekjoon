#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
vector<long long> t;

void init(int node, int s, int e) {
	if (s == e)
		t[node] = v[s];

	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);

		t[node] = min(t[node * 2], t[node * 2 + 1]);
	}
}

long long query(int node, int s, int e, int l, int r) {
	if (r < s || l > e)
		return 1000000001;

	if (l <= s && r >= e)
		return t[node];

	long long lmin = query(node * 2, s, (s + e) / 2, l, r);
	long long rmin = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

	return min(lmin, rmin);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	v = vector<long long>(n);
	t = vector<long long>(4 * n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		long long ans = query(1, 0, n - 1, a - 1, b - 1);
		cout << ans << '\n';
	}
}