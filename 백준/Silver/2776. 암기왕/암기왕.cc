#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int n; cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		int m; cin >> m;

		for (int i = 0; i < m; i++) {
			int val; cin >> val;

			if (binary_search(v.begin(), v.end(), val))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}