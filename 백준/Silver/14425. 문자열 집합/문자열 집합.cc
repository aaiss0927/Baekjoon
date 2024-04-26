#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_set<string> s;
	int n, m; cin >> n >> m;

	while (n--) {
		string str; cin >> str;
		s.insert(str);
	}

	int cnt = 0;

	while (m--) {
		string str; cin >> str;

		if (s.find(str) != s.end()) {
			cnt++;
		}
	}

	cout << cnt;
}