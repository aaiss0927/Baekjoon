#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<string> S;
	int N, M;
	cin >> N >> M;
	string name;

	while (N--) {
		cin >> name;
		S.insert(name);
	}

	int count = 0;
	vector<string> dbj;
	while (M--) {
		cin >> name;
		if (S.find(name) != S.end()) {
			count++;
			dbj.push_back(name);
		}
	}
	sort(dbj.begin(), dbj.end());

	cout << count << '\n';
	for (int i = 0; i < dbj.size(); i++) {
		cout << dbj[i] << '\n';
	}
}