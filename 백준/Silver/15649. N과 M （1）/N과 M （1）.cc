#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool visited[9];

void bt() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = true;
		v.push_back(i);
		bt();
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	bt();
}