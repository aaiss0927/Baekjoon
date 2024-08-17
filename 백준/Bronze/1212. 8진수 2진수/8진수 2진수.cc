#include <iostream>
#include <string>
using namespace std;

string to_binary(char c, int i) {
	string bin = "";
	int num = c - '0';

	while (num) {
		bin = to_string(num % 2) + bin;
		num /= 2;
	}

	if (i != 0) {
		while (bin.length() < 3) {
			bin = "0" + bin;
		}
	}

	return bin;
}

int main() {
	string s; cin >> s;

	if (s == "0") {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		cout << to_binary(s[i], i);
	}
}