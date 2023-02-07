#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	getline(cin, S);

	int len = S.length();
	for (int i = 0; i < len; i++) {
		if (isalpha(S[i])) {
			if (isupper(S[i])) {
				if (S[i] <= 77) {
					S[i] = char(int(S[i]) + 13);
				}
				else {
					S[i] = char(int(S[i]) - 13);
				}
			}
			else {
				if (S[i] <= 109) {
					S[i] = char(int(S[i]) + 13);
				}
				else {
					S[i] = char(int(S[i]) - 13);
				}
			}
		}
	}
	cout << S;
}