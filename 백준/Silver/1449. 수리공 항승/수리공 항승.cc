#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hole[1001];

int main() {
	int n, l; cin >> n >> l;
	int cnt = 0;
	vector<int> poss;

	for (int i = 0; i < n; i++) {
		int pos; cin >> pos;
		hole[pos] = true;
		poss.push_back(pos);
	}

	sort(poss.begin(), poss.end());

	for (const auto& p : poss) {
		if (hole[p]) {
			for (int i = 0; i < l; i++)
				hole[p + i] = false;

			cnt++;
		}
	}

	cout << cnt;
}