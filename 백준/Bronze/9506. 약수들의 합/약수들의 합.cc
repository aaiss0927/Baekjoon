#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (true) {
		cin >> n;
		if (n == -1) {
			break;
		}
		vector<int> div;
		int totalDiv = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				div.push_back(i);
				totalDiv += i;
			}
		}
		
		if (n == totalDiv) {
			cout << n << " = ";
			for (int i = 0; i < div.size() - 1; i++) {
				cout << div[i] << " + ";
			}
			cout << div[div.size() - 1] << '\n';
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
	}
}