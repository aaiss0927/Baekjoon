#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	map<string, string> m;

	for (int i = 0; i < n; i++) {
		string name, state; cin >> name >> state;
		m[name] = state;
	}

	for (auto it = m.rbegin(); it != m.rend(); it++)
		if ((*it).second == "enter") cout << (*it).first << '\n';
}