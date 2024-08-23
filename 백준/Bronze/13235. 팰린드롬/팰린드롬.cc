#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str; cin >> str;
	int s = 0;
	int e = str.length() - 1;;

	while (s <= e) {
		if (str[s] != str[e]) {
			cout << "false";
			return 0;
		}

		s++; e--;
	}

	cout << "true";
}