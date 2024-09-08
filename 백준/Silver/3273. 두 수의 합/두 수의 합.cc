#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;

	int count = 0;

	sort(arr, arr + n);
	int start = 0;
	int end = n - 1;

	while (start < end) {
		if (arr[start] + arr[end] == x) {
			count++;
			start++;
			end--;
		}
		else if (arr[start] + arr[end] > x) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << count;
}