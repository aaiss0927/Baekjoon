#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;

bool check(ll a, ll b, ll c) {
	if (a == c || b == c)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<ll> solution(n);

	for (int i = 0; i < n; i++)
		cin >> solution[i];

	sort(solution.begin(), solution.end());

	ll first, second, third;
	ll sum = LLONG_MAX;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n; j++) {
			ll pair_sum = solution[i] + solution[j];
			auto it = lower_bound(solution.begin(), solution.end(), -(pair_sum));
			int k, l;

			if (it == solution.end()) {
				k = (--it) - solution.begin();

				if (check(solution[i], solution[j], solution[k]) && abs(pair_sum + solution[k]) < sum) {
					first = solution[i];
					second = solution[j];
					third = solution[k];
					sum = abs(pair_sum + solution[k]);
				}
			}

			else {
				k = it - solution.begin();

				if (k == 0) {
					if (check(solution[i], solution[j], solution[k]) && abs(pair_sum + solution[k]) < sum) {
						first = solution[i];
						second = solution[j];
						third = solution[k];
						sum = abs(pair_sum + solution[k]);
					}
				}

				else {
					l = k - 1;

					if (check(solution[i], solution[j], solution[k]) && abs(pair_sum + solution[k]) < sum) {
						if (abs(pair_sum + solution[k]) < sum) {
							first = solution[i];
							second = solution[j];
							third = solution[k];
							sum = abs(pair_sum + solution[k]);
						}
					}

					if (check(solution[i], solution[j], solution[l]) && abs(pair_sum + solution[l]) < sum) {
						if (abs(pair_sum + solution[l]) < sum) {
							first = solution[i];
							second = solution[j];
							third = solution[l];
							sum = abs(pair_sum + solution[l]);
						}
					}
				}
			}
		}
	}

	vector<ll> result;
	result.push_back(first);
	result.push_back(second);
	result.push_back(third);
	sort(result.begin(), result.end());

	cout << result[0] << ' ' << result[1] << ' ' << result[2];
}