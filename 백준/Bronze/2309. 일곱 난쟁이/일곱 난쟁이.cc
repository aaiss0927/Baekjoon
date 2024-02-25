#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += arr[i];
	}
	int C = sum - 100;
	int C_ = C + 1;
	int* num = new int[C_];
	for (int i = 0; i < C + 1; i++) {
		num[i] = 0;
	}

	int p, q;
	for (int i = 0; i < 9; i++) {
		num[arr[i]]++;
	}
	for (int i = 0; i < 9; i++) {
		if (num[C - arr[i]]) {
			p = i;
			break;
		}
	}

	for (int i = p + 1; i < 9; i++) {
		if (arr[i] == C - arr[p]) {
			q = i;
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == p || i == q) {
			continue;
		}
		cout << arr[i] << '\n';
	}

	delete[] num;
	return 0;
}