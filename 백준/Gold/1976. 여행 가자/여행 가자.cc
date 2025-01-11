#include <iostream>
#include <vector>
using namespace std;

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

	int n; cin >> n;
	int m; cin >> m;

	p = vector<int>(n, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;

			if (num)
				uni(i, j);
		}
	}

	int cur;
	bool flag = true;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		num--;

		if (i == 0) {
			cur = find(num);
			continue;
		}

		if (cur != find(num)) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";
}