#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int num;
	vector<int> arr;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	stack<int> s;
	s.push(0);

	vector<int> table(n + 1);
	for (int i = 1; i <= n; i++) {
		table[i] = 0;
	}

	ostringstream strg;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		while (arr[i] != s.top()) {
			if (arr[i] > s.top()) {
				if (table[idx] == 0) {
					s.push(idx);
					table[idx] = 1;
					idx++;
					strg << '+' << '\n';
				}
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		s.pop();
		strg << '-' << '\n';
	}
	cout << strg.str();
}