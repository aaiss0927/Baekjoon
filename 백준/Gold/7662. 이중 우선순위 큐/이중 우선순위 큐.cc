#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--) {
		multiset<int> s;
		int k; cin >> k;

		while (k--) {
			char c; cin >> c;

			if (c == 'I') {
				int n; cin >> n;
				s.insert(n);
			}

			else {
				int op; cin >> op;
				if (s.empty()) continue;

				if (op == 1) {
					auto it = s.end(); it--;
					s.erase(it);
				}

				else {
					auto it = s.begin();
					s.erase(it);
				}
			}
		}

		if (s.empty()) cout << "EMPTY\n";

		else {
			auto maxi = s.end(); maxi--;
			auto mini = s.begin();

			cout << *maxi << ' ' << *mini << '\n';
		}
	}
}