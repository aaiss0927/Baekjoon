#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<long long> solution(n);

	for (int i = 0; i < n; i++)
		cin >> solution[i];

	long long first, second;
	long long sum = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(solution.begin(), solution.end(), -solution[i]);
		int j, k;

		if (it == solution.end()) {
			j = (--it) - solution.begin();

			if (i != j && abs(solution[i] + solution[j]) < sum) {
				first = solution[i];
				second = solution[j];
				sum = abs(solution[i] + solution[j]);
			}
		}

		else {
			j = it - solution.begin();

			if (j == 0) {
				if (i != j && abs(solution[i] + solution[j]) < sum) {
					first = solution[i];
					second = solution[j];
					sum = abs(solution[i] + solution[j]);
				}
			}

			else {
				k = j - 1;

				if (i != j && abs(solution[i] + solution[j]) < abs(solution[i] + solution[k])) {					
					if (abs(solution[i] + solution[j]) < sum) {
						first = solution[i];
						second = solution[j];
						sum = abs(solution[i] + solution[j]);
					}
				}

				else if (i != k && abs(solution[i] + solution[j]) >= abs(solution[i] + solution[k])) {
					if (abs(solution[i] + solution[k]) < sum) {
						first = solution[i];
						second = solution[k];
						sum = abs(solution[i] + solution[k]);
					}
				}
			}
		}
	}

	if (first > second)
		swap(first, second);

	cout << first << ' ' << second;
}