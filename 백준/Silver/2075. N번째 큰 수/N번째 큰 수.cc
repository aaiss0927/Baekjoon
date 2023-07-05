#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; cin >> x;
			pq.push(x);
		}

		while (pq.size() > N) {
			pq.pop();
		}
	}
	cout << pq.top();
}