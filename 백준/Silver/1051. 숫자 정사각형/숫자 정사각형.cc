#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	char** table = new char* [N];
	for (int i = 0; i < N; i++) {
		table[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}
	int count = min(N, M);
	int ans = 1;
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < M - i; k++) {
				if (table[j][k] == table[j + i][k] &&
					table[j][k] == table[j + i][k + i] &&
					table[j][k] == table[j][k + i]) {
					ans = i + 1;
				}
			}
		}
	}
	cout << pow(ans, 2);
}