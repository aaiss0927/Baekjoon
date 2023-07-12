#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> A;

	int N, K;
	cin >> N >> K;
	int count = 0;

	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		A.push_back(x);
	}

	int maxA = A.front();
	int idx = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] <= K) {
			maxA = A[i];
			idx = i;
		}
	}

	while (K) {
		while (K >= maxA) {
			count += (K / maxA);
			K %= maxA;
		}
		idx--;
		maxA = A[idx];
	}

	cout << count;
}