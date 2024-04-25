#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_set<int> s;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;

		if (s.find(num) != s.end()) {
			cout << "1 ";
		}
		
		else {
			cout << "0 ";
		}
	}
}