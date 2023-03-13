#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int* basket = new int[N] {0};
	int i, j, k;
	while (M--) {
		cin >> i >> j >> k;
		for (int l = i - 1; l <= j - 1; l++) {
			basket[l] = k;
		}
	}
	for (int l = 0; l < N; l++) {
		cout << basket[l] << ' ';
	}
}