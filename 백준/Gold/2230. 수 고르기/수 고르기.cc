#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	v = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int mini = INT_MAX;

	for (int i = 0; i < n; i++) {
		int cur = v[i];
		int comp_idx = lower_bound(v.begin() + i, v.end(), cur + m) - v.begin();
		
		if (comp_idx >= n) {
			continue;
		}

		int comp = v[comp_idx];
		mini = min(mini, comp - cur);
	}

	cout << mini;
}