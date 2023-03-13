#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int* basket = new int[N];
	for (int i = 0; i < N; i++) {
		basket[i] = i + 1;
	}
	int i, j;
	while (M--) {
		cin >> i >> j;
		reverse(basket + i - 1, basket + j);
	}
	for (int l = 0; l < N; l++) {
		cout << basket[l] << ' ';
	}
}