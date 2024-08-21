#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<pair<long long, long long>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	long double result = 0;

	for (int i = 0; i < n - 1; i++) {
		result += (v[i].first * v[i + 1].second);
		result -= (v[i].second * v[i + 1].first);
	}

	result += v[n - 1].first * v[0].second;
	result -= v[n - 1].second * v[0].first;

	result /= 2;
	result = abs(result);

	cout << fixed << setprecision(1) << round(result * 10) / 10;
}