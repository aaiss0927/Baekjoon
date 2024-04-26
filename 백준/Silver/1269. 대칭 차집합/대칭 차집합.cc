#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_set<int> s;
	vector<int> v;
	
	int c1, c2; cin >> c1 >> c2;
	int d = 0;

	for (int i = 0; i < c1; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < c2; i++) {
		int num; cin >> num;
		
		if (s.find(num) != s.end()) {
			d++;
		}
	}

	cout << c1 + c2 - 2 * d;
}