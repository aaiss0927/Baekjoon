#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string strg;
	cin >> strg;

	int* num = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	stack<double> S;
	for (int i = 0; i < strg.length(); i++) {
		if (strg[i] >= 'A' && strg[i] <= 'Z') {
			S.push(num[strg[i] - 'A']);
		}
		else if (strg[i] == '+') {
			double first = S.top();
			S.pop();
			double second = S.top();
			S.pop();
			S.push(second + first);
		}
		else if (strg[i] == '-') {
			double first = S.top();
			S.pop();
			double second = S.top();
			S.pop();
			S.push(second - first);
		}
		else if (strg[i] == '*') {
			double first = S.top();
			S.pop();
			double second = S.top();
			S.pop();
			S.push(second * first);
		}
		else if (strg[i] == '/') {
			double first = S.top();
			S.pop();
			double second = S.top();
			S.pop();
			S.push(second / first);
		}
	}
	cout << fixed << setprecision(2) << S.top();
}