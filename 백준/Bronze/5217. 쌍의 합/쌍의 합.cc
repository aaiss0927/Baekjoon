#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int num;
	while (n--) {
		cin >> num;
		cout << "Pairs for " << num << ": ";
		int left = 1;
		while (num - left > left) {
			if (left != 1) {
				cout << ", ";
			}
			cout << left << ' ' << num - left;
			left++;
		}
		cout << '\n';
	}
}