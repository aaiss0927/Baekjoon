#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
vector<pair<long long, long long>> t;

void init(int node, int s, int e) {
	if (s == e)
		t[node] = { v[s], v[s]};

	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);

		int mini = min(t[node * 2].first, t[node * 2 + 1].first);
		int maxi = max(t[node * 2].second, t[node * 2 + 1].second);
		t[node] = { mini, maxi };
	}
}

pair<long long, long long> query(int node, int s, int e, int l, int r) {
	if (r < s || l > e)
		return { 1000000001, -1 };

	if (l <= s && r >= e)
		return t[node];

	pair<int, int> lminmax = query(node * 2, s, (s + e) / 2, l, r);
	pair<int, int> rminmax = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

	int mini = min(lminmax.first, rminmax.first);
	int maxi = max(lminmax.second, rminmax.second);

	return { mini, maxi };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	v = vector<long long>(n);
	t = vector<pair<long long, long long>>(4 * n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		pair<int, int> ans = query(1, 0, n - 1, a - 1, b - 1);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}