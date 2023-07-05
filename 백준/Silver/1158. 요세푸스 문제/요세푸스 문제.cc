#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}

	cout << '<';

	while (Q.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			int top = Q.front();
			Q.pop();
			Q.push(top);
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << Q.front() << '>';
}