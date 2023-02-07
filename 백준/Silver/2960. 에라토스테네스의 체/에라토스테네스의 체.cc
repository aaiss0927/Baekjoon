#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<bool> primeTable(N + 1);
	primeTable[1] = true;

	vector<int> erase;

	for (int i = 2; i <= N; i++) {
		if (primeTable[i]) {
			continue;
		}
		else {
			erase.push_back(i);
		}
		for (int j = 2 * i; j <= N; j += i) {
			if (primeTable[j]) {
				continue;
			}
			primeTable[j] = true;
			erase.push_back(j);			
		}
	}
	cout << erase[K - 1];
}