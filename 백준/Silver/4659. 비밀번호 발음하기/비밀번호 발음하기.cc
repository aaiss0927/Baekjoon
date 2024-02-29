#include <iostream>
using namespace std;

int alpha_cnt[26];

// a b c d e f g h i j
// k l m n o p q r s t
// u v w x y z

bool is_mo(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}

	return false;
}

bool is_valid(string str) {
	for (int i = 0; i < 26; i++) {
		alpha_cnt[i] = 0;
	}

	for (int i = 0; i < str.length(); i++) {
		alpha_cnt[str[i] - 'a']++;
	}

	if (!(alpha_cnt[0] || alpha_cnt[4] || alpha_cnt[8] || alpha_cnt[14] || alpha_cnt[20])) {
		return false;
	}

	for (int i = 2; i < str.length(); i++) {
		if (is_mo(str[i - 2]) && is_mo(str[i - 1]) && is_mo(str[i])) {
			return false;
		}

		else if (!is_mo(str[i - 2]) && !is_mo(str[i - 1]) && !is_mo(str[i])) {
			return false;
		}
	}

	for (int i = 1; i < str.length(); i++) {
		if ((str[i - 1] == str[i]) && (str[i] != 'e' && str[i] != 'o')) {
			return false;
		}
	}

	return true;
}

int main() {
	string str;

	while (cin >> str) {
		if (str == "end") {
			break;
		}

		if (is_valid(str)) {
			cout << "<" << str << "> is acceptable.\n";
		}

		else {
			cout << "<" << str << "> is not acceptable.\n";
		}
	}
}