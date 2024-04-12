#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

bool binary_search(int x) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int m = (s + e) / 2;

		if (x > v[m]) {
			s = m + 1;
		}

		else if (x < v[m]) {
			e = m - 1;
		}

		else {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int m; cin >> m;

	while (m--) {
		int x; cin >> x;
		cout << binary_search(x) << '\n';
	}	
}