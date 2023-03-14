#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> array(N);
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	vector<int> array_(array);
	sort(array_.begin(), array_.end());
	array_.erase(unique(array_.begin(), array_.end()), array_.end());
	for (int i = 0; i < N; i++) {
		auto it = lower_bound(array_.begin(), array_.end(), array[i]);
		cout << it - array_.begin() << ' ';
	}
}