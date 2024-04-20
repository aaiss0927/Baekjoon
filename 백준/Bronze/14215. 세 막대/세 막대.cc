#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> v(3);

	int max = 0;
	int idx_max = -1;

	for (int i = 0; i < 3; i++) {
		cin >> v[i];

		if (v[i] > max) {
			max = v[i];
			idx_max = i;
		}
	}

	int sum = 0;

	for (int i = 0; i < 3; i++) {
		if (i == idx_max) continue;

		sum += v[i];
	}

	if (max >= sum) {
		max = sum - 1;
	}

	cout << sum + max;
}