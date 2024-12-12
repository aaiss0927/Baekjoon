#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int bundle; cin >> bundle;
		pq.push(bundle);
	}

	long long cnt = 0;

	while (pq.size() > 1) {
		long long first = pq.top(); pq.pop();
		long long second = pq.top(); pq.pop();
		long long new_front = first + second;
		cnt += new_front;
		pq.push(new_front);
	}

	cout << cnt;
}