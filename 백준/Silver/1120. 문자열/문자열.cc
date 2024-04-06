#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int get_gap(string s1, string s2) {
	int cnt = 0;

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B; cin >> A >> B;
	int ans = 50;

	for (int i = 0; i <= B.length() - A.length(); i++) {
		ans = min(ans, get_gap(A, B.substr(i, A.length())));
	}

	cout << ans;
}