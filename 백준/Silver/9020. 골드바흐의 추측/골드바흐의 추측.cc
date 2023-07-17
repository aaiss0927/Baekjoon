#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	

	while (T--) {
		int n;
		cin >> n;
		
		vector<bool> primeTable(n + 1);
		primeTable[1] = true;
		for (int i = 2; i <= sqrt(n); i++) {
			if (primeTable[i]) {
				continue;
			}
			for (int j = 2 * i; j <= n; j += i) {
				primeTable[j] = true;
			}
		}

		int k = n / 2;
		while (primeTable[k] || primeTable[n - k]) {
			k--;
		}
		cout << k << ' ' << n - k << '\n';
	}
}