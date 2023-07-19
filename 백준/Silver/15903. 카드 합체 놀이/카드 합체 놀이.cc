#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<long, vector<long>, greater<long>> pq;

	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		pq.push(x);
	}

	while (m--) {
		long first = pq.top(); pq.pop();
		long second = pq.top(); pq.pop();

		pq.push(first + second);
		pq.push(first + second);
	}

	long score = 0;
	for (int i = 0; i < n; i++) {
		score += pq.top();
		pq.pop();
	}

	cout << score;
}