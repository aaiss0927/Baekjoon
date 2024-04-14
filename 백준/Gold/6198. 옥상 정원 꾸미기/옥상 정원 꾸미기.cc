#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<int> h(N);
	vector<int> cnt(N);
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (s.empty()) {
			s.push({ i, h[i] });
			cnt[i] = N - 1 - i;
		}

		else {
			while (!s.empty() && h[i] > s.top().second) {
				s.pop();
			}

			if (s.empty()) {
				cnt[i] += N - 1 - i;
			}

			else {
				cnt[i] += s.top().first - i - 1;
			}

			s.push({ i, h[i] });
		}
	}

	ll sum = 0;

	for (int i = 0; i < N; i++) {
		sum += cnt[i];
	}

	cout << sum;
}