#include <iostream>
#include <queue>
using namespace std;

int n, w, L;
int wsum, t;
queue<int> bridge;
queue<int> trucks;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> w >> L;
	wsum = t = 0;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		trucks.push(a);
	}

	for (int i = 0; i < w; i++)
		bridge.push(0);

	while (!bridge.empty()) {
		wsum -= bridge.front();
		bridge.pop();

		if (!trucks.empty()) {
			if (wsum + trucks.front() <= L) {
				bridge.push(trucks.front());
				wsum += trucks.front();
				trucks.pop();
			}

			else
				bridge.push(0);
		}

		t++;
	}

	cout << t;
}