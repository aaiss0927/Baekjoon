#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[500000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	int m; cin >> m;

	while (m--) {
		int target; cin >> target;
		cout << upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target) << ' ';
	}

	return 0;
}