#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> arr;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2) {
			arr.push_back(n);
		}
	}

	if (arr.empty()) {
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (auto i : arr) {
		sum += i;
	}
	cout << sum << '\n' << *min_element(arr.begin(), arr.end());
}