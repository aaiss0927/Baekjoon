#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string X;
	cin >> X;
	
	vector<int> num;
	int Y = 0;

	for (int i = 0; i < X.length(); i++) {
		num.push_back(X[i] - '0');
	}

	for (int i = 0; i < X.length(); i++) {
		Y += num[i];
	}

	int digit = 1;
	int Y_ = Y;
	while (Y / 10) {
		Y /= 10;
		digit++;
	}
	Y = Y_;

	int count = 1;
	while (Y >= 10) {
		Y = 0;
		for (int i = 0; i < digit; i++) {
			Y += int(Y_ / pow(10, i)) % 10;
		}
		Y_ = Y;
		count++;
	}
	
	if (X.length() == 1) {
		count = 0;
	}
	cout << count << '\n';
	if (Y % 3) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}