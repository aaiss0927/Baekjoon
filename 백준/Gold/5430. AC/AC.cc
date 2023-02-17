#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		deque<int> dq;
		cin.ignore(700000, '[');
		for (int i = 0; i < n; i++) {
			if (i) {
				cin.ignore(700000, ',');
			}
			int num;
			cin >> num;
			dq.push_back(num);
		}
		cin.ignore(1000, ']');

		bool state = true;
		bool flag = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') {
				flag = 1 - flag;
			}
			else if (s[i] == 'D') {
				if (!dq.empty()) {
					if (!flag) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
				else {
					state = false;
					break;
				}
			}
		}
		if (state) {
			if (flag) {
				reverse(dq.begin(), dq.end());
			}
			cout << '[';
			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];
				if (i + 1 != dq.size())
					cout << ',';
			}
			cout << "]\n";
		}
		else {
			cout << "error" << '\n';
		}
	}
}