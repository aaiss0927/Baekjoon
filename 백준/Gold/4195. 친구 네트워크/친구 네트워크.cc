#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> p;

int find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = find(p[x]);
}

int uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return -p[u];

	if (p[v] < p[u])
		swap(u, v);

	p[u] += p[v];
	p[v] = u;
	return -p[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int f; cin >> f;
		p = vector<int>(2 * f, -1);
		unordered_map<string, int> m;
		int idx = 0;

		while (f--) {
			string name_1, name_2; cin >> name_1 >> name_2;
			
			if (m.find(name_1) == m.end())
				m[name_1] = idx++;

			if (m.find(name_2) == m.end())
				m[name_2] = idx++;

			cout << uni(m[name_1], m[name_2]) << '\n';
		}
	}
}