#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	int cnt = 0;

	for (char c : str) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			cnt++;
	}

	cout << cnt;
}