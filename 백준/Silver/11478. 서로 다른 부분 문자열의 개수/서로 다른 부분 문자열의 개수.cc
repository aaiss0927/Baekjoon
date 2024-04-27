#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_set<string> s;
	string str; cin >> str;

	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			s.insert(str.substr(i, j - i + 1));
		}
	}

	cout << s.size();
}