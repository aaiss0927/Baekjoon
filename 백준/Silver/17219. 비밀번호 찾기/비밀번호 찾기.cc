#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, string> m;

	string id;
	string ps;

	while (N--) {
		cin >> id >> ps;
		m.insert(make_pair(id, ps));
	}

	while (M--) {
		cin >> id;
		auto it = m.find(id);
		cout << it->second << '\n';
	}
}