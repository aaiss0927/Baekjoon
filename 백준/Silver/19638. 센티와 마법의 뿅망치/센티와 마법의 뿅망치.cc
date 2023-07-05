#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, H_c, T;
	cin >> N >> H_c >> T;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < N; i++) {
		int H; cin >> H;
		pq.push(H);
	}

	int count = 0;

	if (pq.top() < H_c) {
		cout << "YES\n" << count;
		return 0;
	}

	while (T--) {
		int tmp = pq.top();
		int tmp_ = tmp;
		pq.pop();
		if (tmp > 1) {
			tmp_ = tmp / 2;
		}
		pq.push(tmp_);
		count++;

		if (pq.top() < H_c) {
			cout << "YES\n" << count;
			return 0;
		}
	}
	cout << "NO\n" << pq.top();
}