#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> candy;
vector<int> half;

void set_half() {
	for (int i = 0; i < n; i++)
		half[i] = candy[i] / 2;
}

bool check() {
	for (int i = 1; i < n; i++)
		if (candy[i] != candy[i - 1])
			return false;

	return true;
}

void sup() {
	for (int i = 0; i < n; i++)
		if (candy[i] % 2)
			candy[i]++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		cin >> n;
		candy = vector<int>(n);

		for (int i = 0; i < n; i++)
			cin >> candy[i];

		sup();

		half = vector<int>(n);
		set_half();

		int cnt = 0;

		while (!check()) {
			for (int i = 1; i < n; i++) {
				candy[i] += half[i - 1];
				candy[i] -= half[i];
			}

			candy[0] += half[n - 1];
			candy[0] -= half[0];

			sup();
			set_half();

			cnt++;
		}

		cout << cnt << '\n';
	}
}