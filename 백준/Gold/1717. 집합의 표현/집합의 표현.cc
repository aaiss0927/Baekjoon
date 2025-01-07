#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;
vector<int> p;

int find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	if (p[v] < p[u])
		swap(u, v);

	if (p[v] == p[u])
		p[u]--;

	p[v] = u;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m; cin >> n >> m;
	p = vector<int>(n + 1, -1);

	while (m--) {
		int op, a, b; cin >> op >> a >> b;

		if (op == 0)
			uni(a, b);
		else {
			string result = (find(a) == find(b)) ? "yes" : "no";
			cout << result << '\n';
		}
	}
}