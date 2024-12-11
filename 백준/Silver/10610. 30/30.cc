#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n; cin >> n;
	int len = n.length();
	vector<int> v(len);

	int check_sum = 0;
	bool flag = false;

	for (int i = 0; i < len; i++) {
		v[i] = n[i] - '0';
		check_sum += v[i];
		check_sum %= 3;

		if (v[i] == 0)
			flag = true;
	}

	if (check_sum != 0 || !flag) {
		cout << -1;
		return 0;
	}

	sort(v.rbegin(), v.rend());
	
	for (int i = 0; i < len; i++)
		cout << v[i];
}