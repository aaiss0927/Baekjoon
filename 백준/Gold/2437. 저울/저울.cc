#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> weight(n);

	for (int i = 0; i < n; i++)
		cin >> weight[i];

	sort(weight.begin(), weight.end());

	int pre_sum = 1;

	for (int i = 0; i < n; i++) {
		if (weight[i] > pre_sum)
			break;

		pre_sum += weight[i];
	}

	cout << pre_sum;
}