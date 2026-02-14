#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int w; cin >> w;
		v.push_back(w);
	}

	sort(v.rbegin(), v.rend());
	int max_weight = 0;

	for (int i = 0; i < n; i++) {
		int weight = (i + 1) * v[i];

		if (weight > max_weight) max_weight = weight;
	}

	cout << max_weight;
}