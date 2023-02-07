#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int i = 0; i < ceil(double(N) / 2); i++) {
			cout << '*' << ' ';
		}
		cout << '\n' << ' ';
		for (int i = 0; i < N / 2; i++) {
			cout << '*' << ' ';
		}
		cout << '\n';
	}
}