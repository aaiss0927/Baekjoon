#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int C; cin >> C;
		int Q, D, N, P;

		Q = C / 25;
		C %= 25;
		D = C / 10;
		C %= 10;
		N = C / 5;
		C %= 5;
		P = C;
		
		cout << Q << " " << D << " " << N << " " << P << '\n';
	}
}