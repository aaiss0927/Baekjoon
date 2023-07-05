#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	string log;
	set<string> s;
	int count = 0;

	while (N--) {
		cin >> log;
		if (log == "ENTER") {
			s.clear();
		}
		else {
			if (s.find(log) == s.end()) {
				s.insert(log);
				count++;
			}
		}
	}
	cout << count;
}