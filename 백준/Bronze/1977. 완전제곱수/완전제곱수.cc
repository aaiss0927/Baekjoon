#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<int> square;
	for (int i = M; i <= N; i++) {
		if (sqrt(i) == floor(sqrt(i))) {
			square.push_back(i);
		}
	}

	if (square.empty()) {
		cout << -1;
		return 0;
	}
	
	int sum = 0;
	for (auto i : square) {
		sum += i;
	}
	cout << sum << '\n' << *min_element(square.begin(), square.end());
}