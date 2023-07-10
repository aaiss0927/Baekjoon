#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<string> s;
		string* s_ = new string[n];
		for (int i = 0; i < n; i++) {
			string num; cin >> num;
			s.insert(num);
			s_[i] = num;
		}
		
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s_[i].size(); j++) {
				string temp = s_[i].substr(0, j);
				if (s.find(temp) != s.end()) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}