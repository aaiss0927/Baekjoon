#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int idx = 0;
vector<int> arr;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

long getC(int a, int b) {
	int nm, dn;
	nm = dn = 1;

	for (int i = b; i >= 1; i--) {
		nm *= i + (a - b);
		dn *= i;
		int gcd = GCD(nm, dn);
		nm /= gcd;
		dn /= gcd;
	}

	return nm / dn;
}

void search(int x, vector<vector<int>>& keyset) {
	if (x == 2 * n) {
		if (arr.size() == n) {
			for (int i = 0; i < arr.size(); i++) {
				keyset[idx].push_back(arr[i]);
			}
			idx++;
		}
	}
	else {
		arr.push_back(x + 1);
		search(x + 1, keyset);
		arr.pop_back();
		search(x + 1, keyset);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> n >> m >> k;

	vector<vector<int>> keymap(m, vector<int>(k));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> keymap[i][j];
		}
	}

	
	vector<vector<int>> keyset(getC(2 * n, n));
	search(0, keyset);
	vector<int> count(getC(2 * n, n), 0);

	for (int i = 0; i < getC(2 * n, n); i++) {
		vector<bool> check(2 * n, false);

		for (int j = 0; j < n; j++) {
			check[keyset[i][j] - 1] = true;
		}

		for (int j = 0; j < m; j++) {
			bool flag = true;
			for (int t = 0; t < k; t++) {
				if (!check[keymap[j][t] - 1]) {
					flag = false;
				}
			}
			if (flag) {
				count[i]++;
			}
		}
	}

	sort(count.begin(), count.end());
	cout << count.back();
}