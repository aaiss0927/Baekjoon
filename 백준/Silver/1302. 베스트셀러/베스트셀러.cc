#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	int N; cin >> N;
	string tt;

	while (N--) {
		cin >> tt;
		if (m.find(tt) == m.end()) {
			m.insert(pair<string, int>(tt, 1));
		}
		else {
			m[tt]++;
		}
	}

	int max = 0;
	string max_tt = "";
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		if ((*it).second > max) {
			max = (*it).second;
			max_tt = (*it).first;
		}
	}
	cout << max_tt;
}