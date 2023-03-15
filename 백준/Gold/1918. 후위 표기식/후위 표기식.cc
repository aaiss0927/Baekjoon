#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string strg;
	cin >> strg;
	stack<char> S;
	for (int i = 0; i < strg.length(); i++) {
		if (strg[i] >= 'A' && strg[i] <= 'Z') {
			cout << strg[i];
		}
		else if (strg[i] == '(') {
			S.push(strg[i]);
		}
		else if (strg[i] == ')') {
			while (S.top() != '(') {
				cout << S.top();
				S.pop();
			}
			S.pop();
		}
		else if (strg[i] == '+') {
			while (!S.empty() && S.top() != '(') {
				cout << S.top();
				S.pop();
			}
			S.push(strg[i]);
		}
		else if (strg[i] == '-') {
			while (!S.empty() && S.top() != '(') {
				cout << S.top();
				S.pop();
			}
			S.push(strg[i]);
		}
		else if (strg[i] == '*') {
			while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
				cout << S.top();
				S.pop();
			}
			S.push(strg[i]);
		}
		else if (strg[i] == '/') {
			while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
				cout << S.top();
				S.pop();
			}
			S.push(strg[i]);
		}
	}
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}