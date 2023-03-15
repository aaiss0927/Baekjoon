#include <bits/stdc++.h>
using namespace std;

int dat[10001];
int pos = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s == "push") {
			int X;
			cin >> X;
			dat[pos++] = X;
		}
		else if (s == "pop") {
			if (!pos) {
				cout << -1 << '\n';
			}
			else {
				cout << dat[--pos] << '\n';
			}
		}
		else if (s == "size") {
			cout << pos << '\n';
		}
		else if (s == "empty") {
			if (pos) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else if (s == "top") {
			if (pos) {
				cout << dat[pos - 1] << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
}