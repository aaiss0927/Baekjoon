#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;

	int N;
	cin >> N;

	while (N--) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int X;
			cin >> X;
			DQ.push_front(X);
		}
		else if (s == "push_back") {
			int X;
			cin >> X;
			DQ.push_back(X);
		}
		else if (s == "pop_front") {
			if (!DQ.empty()) {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "pop_back") {
			if (!DQ.empty()) {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << DQ.size() << '\n';
		}
		else if (s == "empty") {
			cout << DQ.empty() << '\n';
		}
		else if (s == "front") {
			if (!DQ.empty()) {
				cout << DQ.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (!DQ.empty()) {
				cout << DQ.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
}