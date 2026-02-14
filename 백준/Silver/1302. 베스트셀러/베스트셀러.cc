#include <iostream>
#include <map>
using namespace std;

map<string, int> m;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string book; cin >> book;
		m[book]++;
	}

	int max_count = 0;
	string max_book = "";
	for (auto it = m.begin(); it != m.end(); it++) {
		if ((*it).second > max_count) {
			max_count = (*it).second;
			max_book = (*it).first;
		}
	}

	cout << max_book;
}