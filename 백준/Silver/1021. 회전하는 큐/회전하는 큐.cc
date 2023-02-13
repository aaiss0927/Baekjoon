#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> table;

	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (M--) {
		int num;
		cin >> num;
		table.push_back(num);
	}
	int count = 0;
	for (int i = 0; i < table.size(); i++) {
		int idx = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[idx] != table[i]) {
				idx++;
			}
		}
		if (idx <= dq.size() / 2) {
			while (dq.front() != table[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}
		else {
			while (dq.front() != table[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
	}
	cout << count;
}