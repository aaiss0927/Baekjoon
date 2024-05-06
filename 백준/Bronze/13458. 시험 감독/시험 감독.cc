#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<long long> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long b, c; cin >> b >> c;

	long long ans = n;

	for (int i = 0; i < n; i++) {
		if (a[i] >= b) {
			ans += ceil(double(a[i] - b) / c);
		}
	}

	cout << ans;
}